;;; The current implementation is a playground. We'll get back to this later.

(eval-and-compile
  (require 'cc-mode))     ; (only) for `c-populate-syntax-table'

;; TODO: remove hardcoded paths
(defvar djp-executable "~/dev/djp/src/out/Debug/bin/djp")
(defvar djp-tmp-buffer "/tmp/djp-mode-buffer")

;; Font faces
(defvar djp-face-annotation-tok-at 'nil)
(defvar djp-face-qualified-id 'nil)
(defvar djp-face-keyword 'font-lock-keyword-face)

;; timer
(defvar djp-mode-parser-timer nil)

(defvar djp-idle-timer-delay 0.2
  "Delay in seconds before re-parsing after user makes changes.")

(defvar djp-mode-parsing nil)

(defvar djp-parse-tree nil
  "The output generated by the parser.")

(defun djp-reset-parser ()
  (setq djp-parse-tree nil))

;; djp-mode
(defvar djp-mode-syntax-table
  (let ((table (make-syntax-table)))
    (c-populate-syntax-table table)
    table)
  "Syntax table used in djp-mode buffers.")

(defvar djp-mode-map
  (let ((map (make-sparse-keymap))
	keys)
    ;(define-key map (kbd "C-m") #'djp-enter-key)
    ;(define-key map (kbd "C-a") #'djp-beginning-of-line)
    map)
  "Keymap used in `djp-mode' buffers.")

(defvar djp-mode-abbrev-table nil
  "Abbrev table in use in `djp-mode' buffers.")
(define-abbrev-table 'djp-mode-abbrev-table ())

;;;###autoload
(defun djp-mode ()
  "Major mode for Java"
  (interactive)
  (kill-all-local-variables)
  (set-syntax-table djp-mode-syntax-table)
  (use-local-map djp-mode-map)
  (setq major-mode 'djp-mode
	mode-name "DJP"
	comment-start "//"
	comment-end "")
  (setq local-abbrev-table djp-mode-abbrev-table)

  ;; We do our own syntax highlighting based on the parse tree.
  ;; However, we want minor modes that add keywords to highlight properly
  ;; We do this by not letting font-lock unfontify anything, and telling it to
  ;; fontify after we re-parse and re-highlight the buffer.  (We currently don't
  ;; do any work with regions other than the whole buffer.)
  (dolist (var '(font-lock-unfontify-buffer-function
                 font-lock-unfontify-region-function))
    (set (make-local-variable var) (lambda (&rest args) t)))

  ;; Don't let font-lock do syntactic (string/comment) fontification.
  (set (make-local-variable #'font-lock-syntactic-face-function)
       (lambda (state) nil))

  (add-hook 'after-change-functions #'djp-mode-edit nil t)

  (djp-reparse)
  (message "baby steps"))

(defun djp-mode-reset-timer ()
  (if djp-mode-parser-timer
      (cancel-timer djp-mode-parser-timer))
  (setq djp-mode-parsing nil)
  (setq djp-mode-parser-timer
	(run-with-idle-timer djp-idle-timer-delay nil #'djp-reparse)))

(defun djp-mode-edit (beg end len)
  "Schedule a new parse after buffer is edited."
  (djp-mode-reset-timer))

(defun djp-reparse ()
  (let (interrupted-p)
    (unless djp-mode-parsing
      (setq djp-mode-parsing t)
      (djp-reset-parser)
      (unwind-protect
	  (progn
	    (djp-with-unmodifying-text-property-changes
	      (remove-text-properties (point-min) (point-max) '(syntax-table))
	      (remove-text-properties (point-min) (point-max) '(face nil))
	      (setq interrupted-p
		    (catch 'interrupted
		      (djp-parse)
		      (djp-do-syntax-highlight)
		      nil))
	      (if interrupted-p
		  (djp-mode-reset-timer))
	      (setq djp-mode-parsing nil)
	      (unless interrupted-p
		(setq djp-mode-parse-timer nil))))))))

(defun djp-parse ()
  "We save the buffer content into a temporary file and trigger the compiler.
The output of the compiler is used to build djp-parse-tree."
  (let (cmd)
    (write-region (point-min) (point-max) djp-tmp-buffer)
    (setq cmd (concat djp-executable " " djp-tmp-buffer))
    (setq djp-parse-tree (read (shell-command-to-string cmd)))))

;;; TODO: this is fragile and error prone
(defun djp-do-syntax-highlight ()
  "Traverse djp-parse-tree applying font-lock face for each node)"
  (loop for node in djp-parse-tree do (eval node)))

;;; Ignored
(defun djp-package-declaration (&rest ignore-completely) nil)
(defun djp-import-declarations (&rest ignore-completely) nil)
(defun djp-import-declaration (&rest ignore-completely) nil)

(defun djp-node-annotation (pos-tok-at err &optional ignore)
  (if djp-face-annotation-tok-at
      (put-text-property pos-tok-at
			 (+ pos-tok-at 1) 'face djp-face-annotation-tok-at)))

(defun djp-node-qualified-id (ini end)
  (if djp-face-qualified-id
      (put-text-property ini end 'face djp-face-qualified-id)))

(defun djp-node-keyword (ini end)
  (if djp-face-keyword
      (put-text-property ini end 'face djp-face-keyword)))

;; Stolen from js2-mode where you can read:
;; `Stolen shamelessly from James Clark's nxml-mode.'
(defmacro djp-with-unmodifying-text-property-changes (&rest body)
  "Evaluate BODY without any text property changes modifying the buffer.
Any text properties changes happen as usual but the changes are not treated as
modifications to the buffer."
  (declare (indent 0) (debug t))
  (let ((modified (make-symbol "modified")))
    `(let ((,modified (buffer-modified-p))
	   (inhibit-read-only t)
	   (inhibit-modification-hooks t)
	   (buffer-undo-list t)
	   (deactivate-mark nil)
	   ;; Apparently these avoid file locking problems.
	   (buffer-file-name nil)
	   (buffer-file-truename nil))
       (unwind-protect
	   (progn ,@body)
	 (unless ,modified
	   (restore-buffer-modified-p nil))))))

(provide 'djp-mode)

;;; djp-mode.el ends here
