//-*- C++ -*-
#ifndef __ASTBIN_H__
#define __ASTBIN_H__
#include <stdint.h> // cstdint
#include <boost/shared_ptr.hpp>

namespace djp {

typedef uint32_t u4;
typedef uint16_t u2;
typedef uint8_t u1;

typedef boost::shared_ptr<struct ClassFile> spClassFile;
typedef boost::shared_ptr<struct ConstantPool> spConstantPool;
typedef boost::shared_ptr<struct CPInfo> spCPInfo;

enum ConstantPoolTag {
  CONSTANT_Class = 7,
  CONSTANT_Fieldref = 9,
  CONSTANT_Methodref = 10,
  CONSTANT_InterfaceMethodref = 11,
  CONSTANT_String = 8,
  CONSTANT_Integer = 3,
  CONSTANT_Float = 4,
  CONSTANT_Long = 5,
  CONSTANT_Double = 6,
  CONSTANT_NameAndType = 12,
  CONSTANT_Utf8 = 1,
  CONSTANT_MethodHandle = 15,
  CONSTANT_MethodType = 16,
  CONSTANT_InvokeDynamic = 18,
};

/// ClassFile {
///        u4             magic;
///        u2             minor_version;
///        u2             major_version;
///        u2             constant_pool_count;
///        cp_info        constant_pool[constant_pool_count-1];
///        u2             access_flags;
///        u2             this_class;
///        u2             super_class;
///        u2             interfaces_count;
///        u2             interfaces[interfaces_count];
///        u2             fields_count;
///        field_info     fields[fields_count];
///        u2             methods_count;
///        method_info    methods[methods_count];
///        u2             attributes_count;
///        attribute_info attributes[attributes_count];
/// }
struct ClassFile {
  u4 magic;
  u2 minor_version;
  u2 major_version;
  u2 constant_pool_count;
  std::vector<spCPInfo> constant_pool;
  // TODO:
  //u2             access_flags;
  //u2             this_class;
  //u2             super_class;
  //u2             interfaces_count;
  //u2             interfaces[interfaces_count];
  //u2             fields_count;
  //field_info     fields[fields_count];
  //u2             methods_count;
  //method_info    methods[methods_count];
  //u2             attributes_count;
  //attribute_info attributes[attributes_count];
};

/// cp_info {
/// u1 tag;
/// u1 info[]; }
struct CPInfo {
  u1 tag;
};

} // namespace
#endif