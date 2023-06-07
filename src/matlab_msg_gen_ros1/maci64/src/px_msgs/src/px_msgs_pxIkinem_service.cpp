// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for px_msgs/pxIkinemRequest
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
#include "px_msgs/pxIkinem.h"
#include "visibility_control.h"
#include "ROSPubSubTemplates.hpp"
#include "ROSServiceTemplates.hpp"
class PX_MSGS_EXPORT px_msgs_msg_pxIkinemRequest_common : public MATLABROSMsgInterface<px_msgs::pxIkinem::Request> {
  public:
    virtual ~px_msgs_msg_pxIkinemRequest_common(){}
    virtual void copy_from_struct(px_msgs::pxIkinem::Request* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const px_msgs::pxIkinem::Request* msg, MultiLibLoader loader, size_t size = 1);
};
  void px_msgs_msg_pxIkinemRequest_common::copy_from_struct(px_msgs::pxIkinem::Request* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //position
        const matlab::data::StructArray position_arr = arr["Position"];
        auto msgClassPtr_position = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_position->copy_from_struct(&msg->position,position_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Position' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Position' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T px_msgs_msg_pxIkinemRequest_common::get_arr(MDFactory_T& factory, const px_msgs::pxIkinem::Request* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Position"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("px_msgs/pxIkinemRequest");
    // position
    auto currentElement_position = (msg + ctr)->position;
    auto msgClassPtr_position = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["Position"] = msgClassPtr_position->get_arr(factory, &currentElement_position, loader);
    }
    return std::move(outArray);
  }
class PX_MSGS_EXPORT px_msgs_msg_pxIkinemResponse_common : public MATLABROSMsgInterface<px_msgs::pxIkinem::Response> {
  public:
    virtual ~px_msgs_msg_pxIkinemResponse_common(){}
    virtual void copy_from_struct(px_msgs::pxIkinem::Response* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const px_msgs::pxIkinem::Response* msg, MultiLibLoader loader, size_t size = 1);
};
  void px_msgs_msg_pxIkinemResponse_common::copy_from_struct(px_msgs::pxIkinem::Response* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //config
        const matlab::data::StructArray config_arr = arr["Config"];
        auto msgClassPtr_config = getCommonObject<px_msgs::pxConfig>("px_msgs_msg_pxConfig_common",loader);
        msgClassPtr_config->copy_from_struct(&msg->config,config_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Config' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Config' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T px_msgs_msg_pxIkinemResponse_common::get_arr(MDFactory_T& factory, const px_msgs::pxIkinem::Response* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Config"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("px_msgs/pxIkinemResponse");
    // config
    auto currentElement_config = (msg + ctr)->config;
    auto msgClassPtr_config = getCommonObject<px_msgs::pxConfig>("px_msgs_msg_pxConfig_common",loader);
    outArray[ctr]["Config"] = msgClassPtr_config->get_arr(factory, &currentElement_config, loader);
    }
    return std::move(outArray);
  } 
class PX_MSGS_EXPORT px_msgs_pxIkinem_service : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~px_msgs_pxIkinem_service(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
    virtual std::shared_ptr<MATLABSvcServerInterface> generateSvcServerInterface();
    virtual std::shared_ptr<MATLABSvcClientInterface> generateSvcClientInterface();
};  
  std::shared_ptr<MATLABPublisherInterface> 
          px_msgs_pxIkinem_service::generatePublisherInterface(ElementType type){
    std::shared_ptr<MATLABPublisherInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSPublisherImpl<px_msgs::pxIkinem::Request,px_msgs_msg_pxIkinemRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSPublisherImpl<px_msgs::pxIkinem::Response,px_msgs_msg_pxIkinemResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
  std::shared_ptr<MATLABSubscriberInterface> 
          px_msgs_pxIkinem_service::generateSubscriberInterface(ElementType type){
    std::shared_ptr<MATLABSubscriberInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSSubscriberImpl<px_msgs::pxIkinem::Request,px_msgs::pxIkinem::Request::ConstPtr,px_msgs_msg_pxIkinemRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSSubscriberImpl<px_msgs::pxIkinem::Response,px_msgs::pxIkinem::Response::ConstPtr,px_msgs_msg_pxIkinemResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
  std::shared_ptr<MATLABSvcServerInterface> 
          px_msgs_pxIkinem_service::generateSvcServerInterface(){
    return std::make_shared<ROSSvcServerImpl<px_msgs::pxIkinem::Request,px_msgs::pxIkinem::Response,px_msgs_msg_pxIkinemRequest_common,px_msgs_msg_pxIkinemResponse_common>>();
  }
  std::shared_ptr<MATLABSvcClientInterface> 
          px_msgs_pxIkinem_service::generateSvcClientInterface(){
    return std::make_shared<ROSSvcClientImpl<px_msgs::pxIkinem,px_msgs::pxIkinem::Request,px_msgs::pxIkinem::Response,px_msgs_msg_pxIkinemRequest_common,px_msgs_msg_pxIkinemResponse_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface> 
          px_msgs_pxIkinem_service::generateRosbagWriterInterface(ElementType type){
    std::shared_ptr<MATLABRosbagWriterInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSBagWriterImpl<px_msgs::pxIkinemRequest,px_msgs_msg_pxIkinemRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSBagWriterImpl<px_msgs::pxIkinemResponse,px_msgs_msg_pxIkinemResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(px_msgs_msg_pxIkinemRequest_common, MATLABROSMsgInterface<px_msgs::pxIkinemRequest>)
CLASS_LOADER_REGISTER_CLASS(px_msgs_msg_pxIkinemResponse_common, MATLABROSMsgInterface<px_msgs::pxIkinemResponse>)
CLASS_LOADER_REGISTER_CLASS(px_msgs_pxIkinem_service, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
