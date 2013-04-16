//-*- C++ -*-
#ifndef __ASTBIN_H__
#define __ASTBIN_H__
#include <stdint.h> // cstdint
#include <memory>

namespace djp {

typedef uint32_t u4;
typedef uint16_t u2;
typedef uint8_t u1;

typedef std::shared_ptr<struct ClassFile> spClassFile;
typedef std::shared_ptr<struct ConstantPool> spConstantPool;
typedef std::shared_ptr<struct CPInfo> spCPInfo;
typedef std::shared_ptr<struct CPItem> spCPItem;
typedef std::shared_ptr<struct CClassInfo> spCClassInfo;
typedef std::shared_ptr<struct CFieldrefInfo> spCFieldrefInfo;
typedef std::shared_ptr<struct CInterfaceMethodrefInfo>
  spCInterfaceMethodrefInfo;
typedef std::shared_ptr<struct CMethodrefInfo> spCMethodrefInfo;
typedef std::shared_ptr<struct CStringInfo> spCStringInfo;
typedef std::shared_ptr<struct CIntegerInfo> spCIntegerInfo;
typedef std::shared_ptr<struct CFloatInfo> spCFloatInfo;
typedef std::shared_ptr<struct CLongInfo> spCLongInfo;
typedef std::shared_ptr<struct CDoubleInfo> spCDoubleInfo;
typedef std::shared_ptr<struct CNameAndTypeInfo> spCNameAndTypeInfo;
typedef std::shared_ptr<struct CUtf8Info> spCUtf8Info;
typedef std::shared_ptr<struct CMethodHandleInfo> spCMethodHandleInfo;
typedef std::shared_ptr<struct CMethodTypeInfo> spCMethodTypeInfo;
typedef std::shared_ptr<struct CInvokeDynamicInfo> spCInvokeDynamicInfo;
typedef std::shared_ptr<struct MethodInfo> spMethodInfo;
typedef std::shared_ptr<struct AttributeInfo> spAttributeInfo;

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

enum ClassAccessAndPropertyModifiers {
  CLASS_ACC_PUBLIC = 0x0001,
  CLASS_ACC_FINAL = 0x0010,
  // Treat superclass methods specially when invoked by the invokespecial
  // instruction.
  CLASS_ACC_SUPER = 0x0020,
  CLASS_ACC_INTERFACE = 0x0200,
  CLASS_ACC_ABSTRACT = 0x0400,
  // Declared synthetic; not present in the source code.
  CLASS_ACC_SYNTHETIC = 0x1000,
  CLASS_ACC_ANNOTATION = 0x2000,
  CLASS_ACC_ENUM = 0x4000,
};

enum MethodAccessAndPropertyFlags {
  METHOD_ACC_PUBLIC = 0x0001,
  METHOD_ACC_PRIVATE = 0x0002,
  METHOD_ACC_PROTECTED = 0x0004,
  METHOD_ACC_STATIC = 0x0008,
  METHOD_ACC_FINAL = 0x0010,
  // Declared synchronized; invocation is wrapped by a monitor use.
  METHOD_ACC_SYNCHRONIZED = 0x0020,
  // A bridge method, generated by the compiler.
  METHOD_ACC_BRIDGE = 0x0040,
  METHOD_ACC_VARARGS = 0x0080,
  METHOD_ACC_NATIVE = 0x0100,
  METHOD_ACC_ABSTRACT = 0x0400,
  METHOD_ACC_STRICT = 0x0800,
  METHOD_ACC_SYNTHETIC = 0x1000,
};

/// ClassFile {
///     u4             magic;
///     u2             minor_version;
///     u2             major_version;
///     u2             constant_pool_count;
///     cp_info        constant_pool[constant_pool_count-1];
///     u2             access_flags;
///     u2             this_class;
///     u2             super_class;
///     u2             interfaces_count;
///     u2             interfaces[interfaces_count];
///     u2             fields_count;
///     field_info     fields[fields_count];
///     u2             methods_count;
///     method_info    methods[methods_count];
///     u2             attributes_count;
///     attribute_info attributes[attributes_count];
/// }
struct ClassFile {
  u4 magic;
  u2 minor_version;
  u2 major_version;
  u2 constant_pool_count;
  spCPInfo constant_pool;
  u2 access_flags;
  u2 this_class;
  u2 super_class;
  u2 interfaces_count;
  std::vector<u2> interfaces;
  u2 fields_count;
  // TODO:
  //field_info fields[fields_count];
  u2 methods_count;
  std::vector<spMethodInfo> methods;
  u2 attributes_count;
  std::vector<spAttributeInfo> attributes;
};

/// cp_info {
///     u1 tag;
///     u1 info[];
/// }
struct CPInfo {
  std::vector<spCPItem> items;
};

struct CPItem {
  u1 tag;
  spCClassInfo cClassInfo;
  spCFieldrefInfo cFieldrefInfo;
  spCMethodrefInfo cMethodrefInfo;
  spCInterfaceMethodrefInfo cInterfaceMethodrefInfo;
  spCStringInfo cStringInfo;
  spCIntegerInfo cIntegerInfo;
  spCFloatInfo cFloatInfo;
  spCLongInfo cLongInfo;
  spCDoubleInfo cDoubleInfo;
  spCNameAndTypeInfo cNameAndTypeInfo;
  spCUtf8Info cUtf8Info;
  spCMethodHandleInfo cMethodHandleInfo;
  spCMethodTypeInfo cMethodTypeInfo;
  spCInvokeDynamicInfo cInvokeDynamicInfo;
};

/// CONSTANT_Class_info {
///     u1 tag;
///     u2 name_index;
/// }
struct CClassInfo {
  //u1 tag; CPItem
  u2 name_index;
};

/// CONSTANT_Fieldref_info {
///     u1 tag;
///     u2 class_index;
///     u2 name_and_type_index;
/// }
struct CFieldrefInfo {
  //u1 tag; CPItem
  u2 class_index;
  u2 name_and_type_index;
};

/// CONSTANT_Methodref_info {
///     u1 tag;
///     u2 class_index;
///     u2 name_and_type_index;
/// }
struct CMethodrefInfo {
  //u1 tag; CPItem
  u2 class_index;
  u2 name_and_type_index;
};

/// CONSTANT_InterfaceMethodref_info {
///     u1 tag;
///     u2 class_index;
///     u2 name_and_type_index;
/// }
struct CInterfaceMethodrefInfo {
  //u1 tag; CPItem
  u2 class_index;
  u2 name_and_type_index;
};

/// CONSTANT_String_info {
///     u1 tag;
///     u2 string_index;
/// }
struct CStringInfo {
  //u1 tag; CPItem
  u2 string_index;
};

/// CONSTANT_Integer_info {
///     u1 tag;
///     u4 bytes;
/// }
struct CIntegerInfo {
  //u1 tag; CPItem
  u4 bytes;
};

/// CONSTANT_Float_info {
///     u1 tag;
///     u4 bytes;
/// }
struct CFloatInfo {
  //u1 tag; CPItem
  u4 bytes;
};

/// CONSTANT_Long_info {
///     u1 tag;
///     u4 high_bytes;
///     u4 low_bytes;
/// }
struct CLongInfo {
  //u1 tag; CPItem
  u4 high_bytes;
  u4 low_bytes;
};

/// CONSTANT_Double_info {
///     u1 tag;
///     u4 high_bytes;
///     u4 low_bytes;
/// }
struct CDoubleInfo {
  //u1 tag; CPItem
  u4 high_bytes;
  u4 low_bytes;
};

/// CONSTANT_NameAndType_info {
///     u2 name_index;
///     u2 descriptor_index;
/// }
struct CNameAndTypeInfo {
  //u1 tag; CPItem
  u2 name_index;
  u2 descriptor_index;
};

/// CONSTANT_Utf8_info {
///     u length;
///     u1 bytes[length];
/// }
struct CUtf8Info {
  //u1 tag; CPItem
  u2 length;
  std::vector<unsigned char> bytes;
};

/// CONSTANT_MethodHandle_info {
///     u1 reference_kind;
///     u2 reference_index;
/// }
struct CMethodHandleInfo {
  //u1 tag; CPItem
  u1 reference_kind;
  u2 reference_index;
};

/// CONSTANT_MethodType_info {
///     u1 reference_kind;
///     u2 reference_index;
/// }
struct CMethodTypeInfo {
  //u1 tag; CPItem
  u2 descriptor_index;
};

/// CONSTANT_InvokeDynamic_info {
///     u2 bootstrap_method_attr_index;
///     u2 name_and_type_index;
/// }
struct CInvokeDynamicInfo {
  //u1 tag; CPItem
  u2 bootstrap_method_attr_index;
  u2 name_and_type_index;
};

/// method_info {
///     u2             access_flags;
///     u2             name_index;
///     u2             descriptor_index;
///     u2             attributes_count;
///     attribute_info attributes[attributes_count];
/// }
struct MethodInfo {
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  std::vector<spAttributeInfo> attributes;
};

/// attribute_info {
///     u2 attribute_name_index;
///     u4 attribute_length;
///     u1 info[attribute_length];
/// }
struct AttributeInfo {
  u2 attribute_name_index;
  u4 attribute_length;
  std::vector<u1> info;
};

} // namespace
#endif
