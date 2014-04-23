// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Request.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Request.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace c4 {

namespace {

const ::google::protobuf::Descriptor* Request_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Request_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* Request_Action_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_Request_2eproto() {
  protobuf_AddDesc_Request_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Request.proto");
  GOOGLE_CHECK(file != NULL);
  Request_descriptor_ = file->message_type(0);
  static const int Request_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, action_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, filename_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, buffer_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, compilationunitlist_),
  };
  Request_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Request_descriptor_,
      Request::default_instance_,
      Request_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Request));
  Request_Action_descriptor_ = Request_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Request_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Request_descriptor_, &Request::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Request_2eproto() {
  delete Request::default_instance_;
  delete Request_reflection_;
}

void protobuf_AddDesc_Request_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rRequest.proto\022\002c4\"\212\001\n\007Request\022\"\n\006actio"
    "n\030\001 \002(\0162\022.c4.Request.Action\022\020\n\010filename\030"
    "\002 \001(\t\022\016\n\006buffer\030\003 \001(\t\022\033\n\023compilationUnit"
    "List\030\004 \003(\t\"\034\n\006Action\022\t\n\005PARSE\020\000\022\007\n\003GET\020\001", 160);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Request.proto", &protobuf_RegisterTypes);
  Request::default_instance_ = new Request();
  Request::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Request_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Request_2eproto {
  StaticDescriptorInitializer_Request_2eproto() {
    protobuf_AddDesc_Request_2eproto();
  }
} static_descriptor_initializer_Request_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* Request_Action_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Request_Action_descriptor_;
}
bool Request_Action_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const Request_Action Request::PARSE;
const Request_Action Request::GET;
const Request_Action Request::Action_MIN;
const Request_Action Request::Action_MAX;
const int Request::Action_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int Request::kActionFieldNumber;
const int Request::kFilenameFieldNumber;
const int Request::kBufferFieldNumber;
const int Request::kCompilationUnitListFieldNumber;
#endif  // !_MSC_VER

Request::Request()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Request::InitAsDefaultInstance() {
}

Request::Request(const Request& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Request::SharedCtor() {
  _cached_size_ = 0;
  action_ = 0;
  filename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  buffer_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Request::~Request() {
  SharedDtor();
}

void Request::SharedDtor() {
  if (filename_ != &::google::protobuf::internal::kEmptyString) {
    delete filename_;
  }
  if (buffer_ != &::google::protobuf::internal::kEmptyString) {
    delete buffer_;
  }
  if (this != default_instance_) {
  }
}

void Request::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Request::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Request_descriptor_;
}

const Request& Request::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Request_2eproto();
  return *default_instance_;
}

Request* Request::default_instance_ = NULL;

Request* Request::New() const {
  return new Request;
}

void Request::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    action_ = 0;
    if (has_filename()) {
      if (filename_ != &::google::protobuf::internal::kEmptyString) {
        filename_->clear();
      }
    }
    if (has_buffer()) {
      if (buffer_ != &::google::protobuf::internal::kEmptyString) {
        buffer_->clear();
      }
    }
  }
  compilationunitlist_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Request::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .c4.Request.Action action = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::c4::Request_Action_IsValid(value)) {
            set_action(static_cast< ::c4::Request_Action >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_filename;
        break;
      }

      // optional string filename = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_filename:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_filename()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->filename().data(), this->filename().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_buffer;
        break;
      }

      // optional string buffer = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_buffer:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_buffer()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->buffer().data(), this->buffer().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_compilationUnitList;
        break;
      }

      // repeated string compilationUnitList = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_compilationUnitList:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_compilationunitlist()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->compilationunitlist(this->compilationunitlist_size() - 1).data(),
            this->compilationunitlist(this->compilationunitlist_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_compilationUnitList;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Request::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .c4.Request.Action action = 1;
  if (has_action()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->action(), output);
  }

  // optional string filename = 2;
  if (has_filename()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->filename().data(), this->filename().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->filename(), output);
  }

  // optional string buffer = 3;
  if (has_buffer()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->buffer().data(), this->buffer().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->buffer(), output);
  }

  // repeated string compilationUnitList = 4;
  for (int i = 0; i < this->compilationunitlist_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8String(
    this->compilationunitlist(i).data(), this->compilationunitlist(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->compilationunitlist(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Request::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .c4.Request.Action action = 1;
  if (has_action()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->action(), target);
  }

  // optional string filename = 2;
  if (has_filename()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->filename().data(), this->filename().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->filename(), target);
  }

  // optional string buffer = 3;
  if (has_buffer()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->buffer().data(), this->buffer().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->buffer(), target);
  }

  // repeated string compilationUnitList = 4;
  for (int i = 0; i < this->compilationunitlist_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->compilationunitlist(i).data(), this->compilationunitlist(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(4, this->compilationunitlist(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Request::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .c4.Request.Action action = 1;
    if (has_action()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->action());
    }

    // optional string filename = 2;
    if (has_filename()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->filename());
    }

    // optional string buffer = 3;
    if (has_buffer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->buffer());
    }

  }
  // repeated string compilationUnitList = 4;
  total_size += 1 * this->compilationunitlist_size();
  for (int i = 0; i < this->compilationunitlist_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->compilationunitlist(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Request::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Request* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Request*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Request::MergeFrom(const Request& from) {
  GOOGLE_CHECK_NE(&from, this);
  compilationunitlist_.MergeFrom(from.compilationunitlist_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_action()) {
      set_action(from.action());
    }
    if (from.has_filename()) {
      set_filename(from.filename());
    }
    if (from.has_buffer()) {
      set_buffer(from.buffer());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Request::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Request::CopyFrom(const Request& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Request::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void Request::Swap(Request* other) {
  if (other != this) {
    std::swap(action_, other->action_);
    std::swap(filename_, other->filename_);
    std::swap(buffer_, other->buffer_);
    compilationunitlist_.Swap(&other->compilationunitlist_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Request::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Request_descriptor_;
  metadata.reflection = Request_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace c4

// @@protoc_insertion_point(global_scope)
