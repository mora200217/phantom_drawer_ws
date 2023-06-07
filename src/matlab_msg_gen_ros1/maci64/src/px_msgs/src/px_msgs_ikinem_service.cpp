// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for px_msgs/ikinemRequest
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
#include "px_msgs/ikinem.h"
#include "visibility_control.h"
#include "ROSPubSubTemplates.hpp"
#include "ROSServiceTemplates.hpp"
class PX_MSGS_EXPORT px_msgs_msg_ikinemRequest_common : public MATLABROSMsgInterface<px_msgs::ikinem::Request> {
  public:
    virtual ~px_msgs_msg_ikinemRequest_common(){}
    virtual void copy_from_struct(px_msgs::ikinem::Request* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const px_msgs::ikinem::Request* msg, MultiLibLoader loader, size_t size = 1);
};
  void px_msgs_msg_ikinemRequest_common::copy_from_struct(px_msgs::ikinem::Request* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //desiredPosition
        const matlab::data::StructArray desiredPosition_arr = arr["DesiredPosition"];
        auto msgClassPtr_desiredPosition = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_desiredPosition->copy_from_struct(&msg->desiredPosition,desiredPosition_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DesiredPosition' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DesiredPosition' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T px_msgs_msg_ikinemRequest_common::get_arr(MDFactory_T& factory, const px_msgs::ikinem::Request* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","DesiredPosition"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("px_msgs/ikinemRequest");
    // desiredPosition
    auto currentElement_desiredPosition = (msg + ctr)->desiredPosition;
    auto msgClassPtr_desiredPosition = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["DesiredPosition"] = msgClassPtr_desiredPosition->get_arr(factory, &currentElement_desiredPosition, loader);
    }
    return std::move(outArray);
  }
class PX_MSGS_EXPORT px_msgs_msg_ikinemResponse_common : public MATLABROSMsgInterface<px_msgs::ikinem::Response> {
  public:
    virtual ~px_msgs_msg_ikinemResponse_common(){}
    virtual void copy_from_struct(px_msgs::ikinem::Response* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const px_msgs::ikinem::Response* msg, MultiLibLoader loader, size_t size = 1);
};
  void px_msgs_msg_ikinemResponse_common::copy_from_struct(px_msgs::ikinem::Response* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //robotConfiguration
        const matlab::data::StructArray robotConfiguration_arr = arr["RobotConfiguration"];
        auto msgClassPtr_robotConfiguration = getCommonObject<px_msgs::pxConfigVector>("px_msgs_msg_pxConfigVector_common",loader);
        msgClassPtr_robotConfiguration->copy_from_struct(&msg->robotConfiguration,robotConfiguration_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'RobotConfiguration' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'RobotConfiguration' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T px_msgs_msg_ikinemResponse_common::get_arr(MDFactory_T& factory, const px_msgs::ikinem::Response* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","RobotConfiguration"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("px_msgs/ikinemResponse");
    // robotConfiguration
    auto currentElement_robotConfiguration = (msg + ctr)->robotConfiguration;
    auto msgClassPtr_robotConfiguration = getCommonObject<px_msgs::pxConfigVector>("px_msgs_msg_pxConfigVector_common",loader);
    outArray[ctr]["RobotConfiguration"] = msgClassPtr_robotConfiguration->get_arr(factory, &currentElement_robotConfiguration, loader);
    }
    return std::move(outArray);
  } 
class PX_MSGS_EXPORT px_msgs_ikinem_service : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~px_msgs_ikinem_service(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
    virtual std::shared_ptr<MATLABSvcServerInterface> generateSvcServerInterface();
    virtual std::shared_ptr<MATLABSvcClientInterface> generateSvcClientInterface();
};  
  std::shared_ptr<MATLABPublisherInterface> 
          px_msgs_ikinem_service::generatePublisherInterface(ElementType type){
    std::shared_ptr<MATLABPublisherInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSPublisherImpl<px_msgs::ikinem::Request,px_msgs_msg_ikinemRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSPublisherImpl<px_msgs::ikinem::Response,px_msgs_msg_ikinemResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
  std::shared_ptr<MATLABSubscriberInterface> 
          px_msgs_ikinem_service::generateSubscriberInterface(ElementType type){
    std::shared_ptr<MATLABSubscriberInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSSubscriberImpl<px_msgs::ikinem::Request,px_msgs::ikinem::Request::ConstPtr,px_msgs_msg_ikinemRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSSubscriberImpl<px_msgs::ikinem::Response,px_msgs::ikinem::Response::ConstPtr,px_msgs_msg_ikinemResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
  std::shared_ptr<MATLABSvcServerInterface> 
          px_msgs_ikinem_service::generateSvcServerInterface(){
    return std::make_shared<ROSSvcServerImpl<px_msgs::ikinem::Request,px_msgs::ikinem::Response,px_msgs_msg_ikinemRequest_common,px_msgs_msg_ikinemResponse_common>>();
  }
  std::shared_ptr<MATLABSvcClientInterface> 
          px_msgs_ikinem_service::generateSvcClientInterface(){
    return std::make_shared<ROSSvcClientImpl<px_msgs::ikinem,px_msgs::ikinem::Request,px_msgs::ikinem::Response,px_msgs_msg_ikinemRequest_common,px_msgs_msg_ikinemResponse_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface> 
          px_msgs_ikinem_service::generateRosbagWriterInterface(ElementType type){
    std::shared_ptr<MATLABRosbagWriterInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSBagWriterImpl<px_msgs::ikinemRequest,px_msgs_msg_ikinemRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSBagWriterImpl<px_msgs::ikinemResponse,px_msgs_msg_ikinemResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(px_msgs_msg_ikinemRequest_common, MATLABROSMsgInterface<px_msgs::ikinemRequest>)
CLASS_LOADER_REGISTER_CLASS(px_msgs_msg_ikinemResponse_common, MATLABROSMsgInterface<px_msgs::ikinemResponse>)
CLASS_LOADER_REGISTER_CLASS(px_msgs_ikinem_service, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
