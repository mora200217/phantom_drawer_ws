// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for px_msgs/gripperPoseRequest
#include "boost/date_time.hpp"
#include "boost/shared_array.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4267)
#pragma warning(disable : 4068)
#pragma warning(disable : 4245)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "ros/ros.h"
#include "px_msgs/gripperPose.h"
#include "visibility_control.h"
#include "ROSPubSubTemplates.hpp"
#include "ROSServiceTemplates.hpp"
class PX_MSGS_EXPORT px_msgs_msg_gripperPoseRequest_common : public MATLABROSMsgInterface<px_msgs::gripperPose::Request> {
  public:
    virtual ~px_msgs_msg_gripperPoseRequest_common(){}
    virtual void copy_from_struct(px_msgs::gripperPose::Request* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const px_msgs::gripperPose::Request* msg, MultiLibLoader loader, size_t size = 1);
};
  void px_msgs_msg_gripperPoseRequest_common::copy_from_struct(px_msgs::gripperPose::Request* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //desiredGripperPose
        const matlab::data::TypedArray<double> desiredGripperPose_arr = arr["DesiredGripperPose"];
        msg->desiredGripperPose = desiredGripperPose_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DesiredGripperPose' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DesiredGripperPose' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T px_msgs_msg_gripperPoseRequest_common::get_arr(MDFactory_T& factory, const px_msgs::gripperPose::Request* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","DesiredGripperPose"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("px_msgs/gripperPoseRequest");
    // desiredGripperPose
    auto currentElement_desiredGripperPose = (msg + ctr)->desiredGripperPose;
    outArray[ctr]["DesiredGripperPose"] = factory.createScalar(currentElement_desiredGripperPose);
    }
    return std::move(outArray);
  }
class PX_MSGS_EXPORT px_msgs_msg_gripperPoseResponse_common : public MATLABROSMsgInterface<px_msgs::gripperPose::Response> {
  public:
    virtual ~px_msgs_msg_gripperPoseResponse_common(){}
    virtual void copy_from_struct(px_msgs::gripperPose::Response* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const px_msgs::gripperPose::Response* msg, MultiLibLoader loader, size_t size = 1);
};
  void px_msgs_msg_gripperPoseResponse_common::copy_from_struct(px_msgs::gripperPose::Response* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
  }
  //----------------------------------------------------------------------------
  MDArray_T px_msgs_msg_gripperPoseResponse_common::get_arr(MDFactory_T& factory, const px_msgs::gripperPose::Response* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("px_msgs/gripperPoseResponse");
    }
    return std::move(outArray);
  } 
class PX_MSGS_EXPORT px_msgs_gripperPose_service : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~px_msgs_gripperPose_service(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
    virtual std::shared_ptr<MATLABSvcServerInterface> generateSvcServerInterface();
    virtual std::shared_ptr<MATLABSvcClientInterface> generateSvcClientInterface();
};  
  std::shared_ptr<MATLABPublisherInterface> 
          px_msgs_gripperPose_service::generatePublisherInterface(ElementType type){
    std::shared_ptr<MATLABPublisherInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSPublisherImpl<px_msgs::gripperPose::Request,px_msgs_msg_gripperPoseRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSPublisherImpl<px_msgs::gripperPose::Response,px_msgs_msg_gripperPoseResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
  std::shared_ptr<MATLABSubscriberInterface> 
          px_msgs_gripperPose_service::generateSubscriberInterface(ElementType type){
    std::shared_ptr<MATLABSubscriberInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSSubscriberImpl<px_msgs::gripperPose::Request,px_msgs::gripperPose::Request::ConstPtr,px_msgs_msg_gripperPoseRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSSubscriberImpl<px_msgs::gripperPose::Response,px_msgs::gripperPose::Response::ConstPtr,px_msgs_msg_gripperPoseResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
  std::shared_ptr<MATLABSvcServerInterface> 
          px_msgs_gripperPose_service::generateSvcServerInterface(){
    return std::make_shared<ROSSvcServerImpl<px_msgs::gripperPose::Request,px_msgs::gripperPose::Response,px_msgs_msg_gripperPoseRequest_common,px_msgs_msg_gripperPoseResponse_common>>();
  }
  std::shared_ptr<MATLABSvcClientInterface> 
          px_msgs_gripperPose_service::generateSvcClientInterface(){
    return std::make_shared<ROSSvcClientImpl<px_msgs::gripperPose,px_msgs::gripperPose::Request,px_msgs::gripperPose::Response,px_msgs_msg_gripperPoseRequest_common,px_msgs_msg_gripperPoseResponse_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface> 
          px_msgs_gripperPose_service::generateRosbagWriterInterface(ElementType type){
    std::shared_ptr<MATLABRosbagWriterInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSBagWriterImpl<px_msgs::gripperPoseRequest,px_msgs_msg_gripperPoseRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSBagWriterImpl<px_msgs::gripperPoseResponse,px_msgs_msg_gripperPoseResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(px_msgs_msg_gripperPoseRequest_common, MATLABROSMsgInterface<px_msgs::gripperPoseRequest>)
CLASS_LOADER_REGISTER_CLASS(px_msgs_msg_gripperPoseResponse_common, MATLABROSMsgInterface<px_msgs::gripperPoseResponse>)
CLASS_LOADER_REGISTER_CLASS(px_msgs_gripperPose_service, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
