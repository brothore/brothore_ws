// Generated by gencpp from file lino_msgs/Imu.msg
// DO NOT EDIT!


#ifndef LINO_MSGS_MESSAGE_IMU_H
#define LINO_MSGS_MESSAGE_IMU_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Quaternion.h>

namespace lino_msgs
{
template <class ContainerAllocator>
struct Imu_
{
  typedef Imu_<ContainerAllocator> Type;

  Imu_()
    : linear_acceleration()
    , angular_velocity()
    , magnetic_field()
    , orientation()
    , roll(0.0)
    , pitch(0.0)
    , yaw(0.0)  {
    }
  Imu_(const ContainerAllocator& _alloc)
    : linear_acceleration(_alloc)
    , angular_velocity(_alloc)
    , magnetic_field(_alloc)
    , orientation(_alloc)
    , roll(0.0)
    , pitch(0.0)
    , yaw(0.0)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _linear_acceleration_type;
  _linear_acceleration_type linear_acceleration;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _angular_velocity_type;
  _angular_velocity_type angular_velocity;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _magnetic_field_type;
  _magnetic_field_type magnetic_field;

   typedef  ::geometry_msgs::Quaternion_<ContainerAllocator>  _orientation_type;
  _orientation_type orientation;

   typedef float _roll_type;
  _roll_type roll;

   typedef float _pitch_type;
  _pitch_type pitch;

   typedef float _yaw_type;
  _yaw_type yaw;





  typedef boost::shared_ptr< ::lino_msgs::Imu_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::lino_msgs::Imu_<ContainerAllocator> const> ConstPtr;

}; // struct Imu_

typedef ::lino_msgs::Imu_<std::allocator<void> > Imu;

typedef boost::shared_ptr< ::lino_msgs::Imu > ImuPtr;
typedef boost::shared_ptr< ::lino_msgs::Imu const> ImuConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::lino_msgs::Imu_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::lino_msgs::Imu_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::lino_msgs::Imu_<ContainerAllocator1> & lhs, const ::lino_msgs::Imu_<ContainerAllocator2> & rhs)
{
  return lhs.linear_acceleration == rhs.linear_acceleration &&
    lhs.angular_velocity == rhs.angular_velocity &&
    lhs.magnetic_field == rhs.magnetic_field &&
    lhs.orientation == rhs.orientation &&
    lhs.roll == rhs.roll &&
    lhs.pitch == rhs.pitch &&
    lhs.yaw == rhs.yaw;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::lino_msgs::Imu_<ContainerAllocator1> & lhs, const ::lino_msgs::Imu_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace lino_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::lino_msgs::Imu_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lino_msgs::Imu_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lino_msgs::Imu_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lino_msgs::Imu_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lino_msgs::Imu_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lino_msgs::Imu_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::lino_msgs::Imu_<ContainerAllocator> >
{
  static const char* value()
  {
    return "12ad91b5c21bab192e85893ad7c3cb1a";
  }

  static const char* value(const ::lino_msgs::Imu_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x12ad91b5c21bab19ULL;
  static const uint64_t static_value2 = 0x2e85893ad7c3cb1aULL;
};

template<class ContainerAllocator>
struct DataType< ::lino_msgs::Imu_<ContainerAllocator> >
{
  static const char* value()
  {
    return "lino_msgs/Imu";
  }

  static const char* value(const ::lino_msgs::Imu_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::lino_msgs::Imu_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Vector3 linear_acceleration\n"
"geometry_msgs/Vector3 angular_velocity\n"
"geometry_msgs/Vector3 magnetic_field\n"
"geometry_msgs/Quaternion orientation\n"
"float32 roll\n"
"float32 pitch\n"
"float32 yaw\n"
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
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::lino_msgs::Imu_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::lino_msgs::Imu_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.linear_acceleration);
      stream.next(m.angular_velocity);
      stream.next(m.magnetic_field);
      stream.next(m.orientation);
      stream.next(m.roll);
      stream.next(m.pitch);
      stream.next(m.yaw);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Imu_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::lino_msgs::Imu_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::lino_msgs::Imu_<ContainerAllocator>& v)
  {
    s << indent << "linear_acceleration: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.linear_acceleration);
    s << indent << "angular_velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.angular_velocity);
    s << indent << "magnetic_field: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.magnetic_field);
    s << indent << "orientation: ";
    s << std::endl;
    Printer< ::geometry_msgs::Quaternion_<ContainerAllocator> >::stream(s, indent + "  ", v.orientation);
    s << indent << "roll: ";
    Printer<float>::stream(s, indent + "  ", v.roll);
    s << indent << "pitch: ";
    Printer<float>::stream(s, indent + "  ", v.pitch);
    s << indent << "yaw: ";
    Printer<float>::stream(s, indent + "  ", v.yaw);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LINO_MSGS_MESSAGE_IMU_H
