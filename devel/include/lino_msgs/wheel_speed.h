// Generated by gencpp from file lino_msgs/wheel_speed.msg
// DO NOT EDIT!


#ifndef LINO_MSGS_MESSAGE_WHEEL_SPEED_H
#define LINO_MSGS_MESSAGE_WHEEL_SPEED_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace lino_msgs
{
template <class ContainerAllocator>
struct wheel_speed_
{
  typedef wheel_speed_<ContainerAllocator> Type;

  wheel_speed_()
    : L1(0.0)
    , L2(0.0)
    , L3(0.0)
    , R1(0.0)
    , R2(0.0)
    , R3(0.0)
    , L_SPEED(0.0)
    , R_SPEED(0.0)
    , L1_PID(0.0)
    , L2_PID(0.0)
    , L3_PID(0.0)
    , R1_PID(0.0)
    , R2_PID(0.0)
    , R3_PID(0.0)  {
    }
  wheel_speed_(const ContainerAllocator& _alloc)
    : L1(0.0)
    , L2(0.0)
    , L3(0.0)
    , R1(0.0)
    , R2(0.0)
    , R3(0.0)
    , L_SPEED(0.0)
    , R_SPEED(0.0)
    , L1_PID(0.0)
    , L2_PID(0.0)
    , L3_PID(0.0)
    , R1_PID(0.0)
    , R2_PID(0.0)
    , R3_PID(0.0)  {
  (void)_alloc;
    }



   typedef float _L1_type;
  _L1_type L1;

   typedef float _L2_type;
  _L2_type L2;

   typedef float _L3_type;
  _L3_type L3;

   typedef float _R1_type;
  _R1_type R1;

   typedef float _R2_type;
  _R2_type R2;

   typedef float _R3_type;
  _R3_type R3;

   typedef float _L_SPEED_type;
  _L_SPEED_type L_SPEED;

   typedef float _R_SPEED_type;
  _R_SPEED_type R_SPEED;

   typedef float _L1_PID_type;
  _L1_PID_type L1_PID;

   typedef float _L2_PID_type;
  _L2_PID_type L2_PID;

   typedef float _L3_PID_type;
  _L3_PID_type L3_PID;

   typedef float _R1_PID_type;
  _R1_PID_type R1_PID;

   typedef float _R2_PID_type;
  _R2_PID_type R2_PID;

   typedef float _R3_PID_type;
  _R3_PID_type R3_PID;





  typedef boost::shared_ptr< ::lino_msgs::wheel_speed_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::lino_msgs::wheel_speed_<ContainerAllocator> const> ConstPtr;

}; // struct wheel_speed_

typedef ::lino_msgs::wheel_speed_<std::allocator<void> > wheel_speed;

typedef boost::shared_ptr< ::lino_msgs::wheel_speed > wheel_speedPtr;
typedef boost::shared_ptr< ::lino_msgs::wheel_speed const> wheel_speedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::lino_msgs::wheel_speed_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::lino_msgs::wheel_speed_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::lino_msgs::wheel_speed_<ContainerAllocator1> & lhs, const ::lino_msgs::wheel_speed_<ContainerAllocator2> & rhs)
{
  return lhs.L1 == rhs.L1 &&
    lhs.L2 == rhs.L2 &&
    lhs.L3 == rhs.L3 &&
    lhs.R1 == rhs.R1 &&
    lhs.R2 == rhs.R2 &&
    lhs.R3 == rhs.R3 &&
    lhs.L_SPEED == rhs.L_SPEED &&
    lhs.R_SPEED == rhs.R_SPEED &&
    lhs.L1_PID == rhs.L1_PID &&
    lhs.L2_PID == rhs.L2_PID &&
    lhs.L3_PID == rhs.L3_PID &&
    lhs.R1_PID == rhs.R1_PID &&
    lhs.R2_PID == rhs.R2_PID &&
    lhs.R3_PID == rhs.R3_PID;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::lino_msgs::wheel_speed_<ContainerAllocator1> & lhs, const ::lino_msgs::wheel_speed_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace lino_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::lino_msgs::wheel_speed_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lino_msgs::wheel_speed_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lino_msgs::wheel_speed_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lino_msgs::wheel_speed_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lino_msgs::wheel_speed_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lino_msgs::wheel_speed_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::lino_msgs::wheel_speed_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dcc44326156228f397c3cb547e1a862c";
  }

  static const char* value(const ::lino_msgs::wheel_speed_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdcc44326156228f3ULL;
  static const uint64_t static_value2 = 0x97c3cb547e1a862cULL;
};

template<class ContainerAllocator>
struct DataType< ::lino_msgs::wheel_speed_<ContainerAllocator> >
{
  static const char* value()
  {
    return "lino_msgs/wheel_speed";
  }

  static const char* value(const ::lino_msgs::wheel_speed_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::lino_msgs::wheel_speed_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 L1\n"
"float32 L2\n"
"float32 L3\n"
"float32 R1\n"
"float32 R2\n"
"float32 R3\n"
"float32 L_SPEED\n"
"float32 R_SPEED\n"
"float32 L1_PID\n"
"float32 L2_PID\n"
"float32 L3_PID\n"
"float32 R1_PID\n"
"float32 R2_PID\n"
"float32 R3_PID\n"
;
  }

  static const char* value(const ::lino_msgs::wheel_speed_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::lino_msgs::wheel_speed_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.L1);
      stream.next(m.L2);
      stream.next(m.L3);
      stream.next(m.R1);
      stream.next(m.R2);
      stream.next(m.R3);
      stream.next(m.L_SPEED);
      stream.next(m.R_SPEED);
      stream.next(m.L1_PID);
      stream.next(m.L2_PID);
      stream.next(m.L3_PID);
      stream.next(m.R1_PID);
      stream.next(m.R2_PID);
      stream.next(m.R3_PID);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct wheel_speed_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::lino_msgs::wheel_speed_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::lino_msgs::wheel_speed_<ContainerAllocator>& v)
  {
    s << indent << "L1: ";
    Printer<float>::stream(s, indent + "  ", v.L1);
    s << indent << "L2: ";
    Printer<float>::stream(s, indent + "  ", v.L2);
    s << indent << "L3: ";
    Printer<float>::stream(s, indent + "  ", v.L3);
    s << indent << "R1: ";
    Printer<float>::stream(s, indent + "  ", v.R1);
    s << indent << "R2: ";
    Printer<float>::stream(s, indent + "  ", v.R2);
    s << indent << "R3: ";
    Printer<float>::stream(s, indent + "  ", v.R3);
    s << indent << "L_SPEED: ";
    Printer<float>::stream(s, indent + "  ", v.L_SPEED);
    s << indent << "R_SPEED: ";
    Printer<float>::stream(s, indent + "  ", v.R_SPEED);
    s << indent << "L1_PID: ";
    Printer<float>::stream(s, indent + "  ", v.L1_PID);
    s << indent << "L2_PID: ";
    Printer<float>::stream(s, indent + "  ", v.L2_PID);
    s << indent << "L3_PID: ";
    Printer<float>::stream(s, indent + "  ", v.L3_PID);
    s << indent << "R1_PID: ";
    Printer<float>::stream(s, indent + "  ", v.R1_PID);
    s << indent << "R2_PID: ";
    Printer<float>::stream(s, indent + "  ", v.R2_PID);
    s << indent << "R3_PID: ";
    Printer<float>::stream(s, indent + "  ", v.R3_PID);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LINO_MSGS_MESSAGE_WHEEL_SPEED_H
