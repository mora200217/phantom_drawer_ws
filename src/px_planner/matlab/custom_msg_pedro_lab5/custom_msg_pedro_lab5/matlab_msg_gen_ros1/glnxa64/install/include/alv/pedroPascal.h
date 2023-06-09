// Generated by gencpp from file alv/pedroPascal.msg
// DO NOT EDIT!


#ifndef ALV_MESSAGE_PEDROPASCAL_H
#define ALV_MESSAGE_PEDROPASCAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Vector3.h>

namespace alv
{
template <class ContainerAllocator>
struct pedroPascal_
{
  typedef pedroPascal_<ContainerAllocator> Type;

  pedroPascal_()
    : positions()
    , x(0.0)
    , y(0.0)
    , z(0.0)  {
    }
  pedroPascal_(const ContainerAllocator& _alloc)
    : positions(_alloc)
    , x(0.0)
    , y(0.0)
    , z(0.0)  {
  (void)_alloc;
    }



   typedef std::vector< ::geometry_msgs::Vector3_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Vector3_<ContainerAllocator> >::other >  _positions_type;
  _positions_type positions;

   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;





  typedef boost::shared_ptr< ::alv::pedroPascal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::alv::pedroPascal_<ContainerAllocator> const> ConstPtr;

}; // struct pedroPascal_

typedef ::alv::pedroPascal_<std::allocator<void> > pedroPascal;

typedef boost::shared_ptr< ::alv::pedroPascal > pedroPascalPtr;
typedef boost::shared_ptr< ::alv::pedroPascal const> pedroPascalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::alv::pedroPascal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::alv::pedroPascal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::alv::pedroPascal_<ContainerAllocator1> & lhs, const ::alv::pedroPascal_<ContainerAllocator2> & rhs)
{
  return lhs.positions == rhs.positions &&
    lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::alv::pedroPascal_<ContainerAllocator1> & lhs, const ::alv::pedroPascal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace alv

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::alv::pedroPascal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::alv::pedroPascal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::alv::pedroPascal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::alv::pedroPascal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::alv::pedroPascal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::alv::pedroPascal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::alv::pedroPascal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2683d6a07869c87203975100587e103c";
  }

  static const char* value(const ::alv::pedroPascal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2683d6a07869c872ULL;
  static const uint64_t static_value2 = 0x03975100587e103cULL;
};

template<class ContainerAllocator>
struct DataType< ::alv::pedroPascal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "alv/pedroPascal";
  }

  static const char* value(const ::alv::pedroPascal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::alv::pedroPascal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Vector3[] positions\n"
"	float64 x\n"
"	float64 y\n"
"	float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::alv::pedroPascal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::alv::pedroPascal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.positions);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct pedroPascal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::alv::pedroPascal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::alv::pedroPascal_<ContainerAllocator>& v)
  {
    s << indent << "positions[]" << std::endl;
    for (size_t i = 0; i < v.positions.size(); ++i)
    {
      s << indent << "  positions[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "    ", v.positions[i]);
    }
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ALV_MESSAGE_PEDROPASCAL_H
