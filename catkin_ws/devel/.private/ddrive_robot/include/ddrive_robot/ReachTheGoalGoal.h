// Generated by gencpp from file ddrive_robot/ReachTheGoalGoal.msg
// DO NOT EDIT!


#ifndef DDRIVE_ROBOT_MESSAGE_REACHTHEGOALGOAL_H
#define DDRIVE_ROBOT_MESSAGE_REACHTHEGOALGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ddrive_robot
{
template <class ContainerAllocator>
struct ReachTheGoalGoal_
{
  typedef ReachTheGoalGoal_<ContainerAllocator> Type;

  ReachTheGoalGoal_()
    : call_mission(false)  {
    }
  ReachTheGoalGoal_(const ContainerAllocator& _alloc)
    : call_mission(false)  {
  (void)_alloc;
    }



   typedef uint8_t _call_mission_type;
  _call_mission_type call_mission;





  typedef boost::shared_ptr< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> const> ConstPtr;

}; // struct ReachTheGoalGoal_

typedef ::ddrive_robot::ReachTheGoalGoal_<std::allocator<void> > ReachTheGoalGoal;

typedef boost::shared_ptr< ::ddrive_robot::ReachTheGoalGoal > ReachTheGoalGoalPtr;
typedef boost::shared_ptr< ::ddrive_robot::ReachTheGoalGoal const> ReachTheGoalGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator1> & lhs, const ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator2> & rhs)
{
  return lhs.call_mission == rhs.call_mission;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator1> & lhs, const ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ddrive_robot

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fd12d66d4470b62966496f4d8305098c";
  }

  static const char* value(const ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfd12d66d4470b629ULL;
  static const uint64_t static_value2 = 0x66496f4d8305098cULL;
};

template<class ContainerAllocator>
struct DataType< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ddrive_robot/ReachTheGoalGoal";
  }

  static const char* value(const ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#Goal\n"
"bool call_mission\n"
"\n"
;
  }

  static const char* value(const ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.call_mission);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReachTheGoalGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ddrive_robot::ReachTheGoalGoal_<ContainerAllocator>& v)
  {
    s << indent << "call_mission: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.call_mission);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DDRIVE_ROBOT_MESSAGE_REACHTHEGOALGOAL_H