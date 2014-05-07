#include "c4/common/ProjectHandler.h"

namespace c4 {

/**
 * Process a request coming from the client.
 */
Response ProjectHandler::process(Request request) {
  Response response;

  if (!request.IsInitialized()) {
    // TODO: error invalid request
    return response;
  }

  std::string projectId = request.projectid();
  spProject project = getProject(projectId);

  // get project information
  if (request.action() == Request::PROJECT) {
    // TODO:
    return response;
  }

  // compile each unit
  if (request.action() == Request::COMPILE) {
    for (int i = 0; i < request.compilationunits_size(); i++) {
      Request::CompilationUnit reqUnit = request.compilationunits(i);
      spCompilationUnit unit = std::shared_ptr<CompilationUnit>(
        new CompilationUnit(reqUnit.filename(), reqUnit.buffer()));
      project->compile(unit);

      // We assume that the first compilation unit is the active buffer on emacs
      // and the only one interested in receiving buffer information for syntax
      // highlighting and alike.
      if (i == 0) {
        response.set_code(Response::OK_COMPILE);
        response.set_body(unit->output);
      }
    }

    // TODO: set default response to error
    return response;
  }

  // TODO: invalid action
  return response;
}

/**
 * Look for the project defined by the projectId. If no project exists we create
 * one.
 */
spProject ProjectHandler::getProject(std::string projectId) {
  auto it = projects.find(projectId);
  if (it == projects.end()) {
    spProject project = std::shared_ptr<Project>(new Project(projectId));
    projects[projectId] = project;
    return project;
  }

  return it->second;
}

}
