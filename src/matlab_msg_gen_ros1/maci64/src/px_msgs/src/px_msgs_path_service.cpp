// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for px_msgs/pathRequest
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
#include "px_msgs/path.h"
#include "visibility_control.h"
#include "ROSPubSubTemplates.hpp"
#include "ROSServiceTemplates.hpp"
class PX_MSGS_EXPORT px_msgs_msg_pathRequest_common : public MATLABROSMsgInterface<px_msgs::path::Request> {
  public:
    virtual ~px_msgs_msg_pathRequest_common(){}
    virtual void copy_from_struct(px_msgs::path::Request* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const px_msgs::path::Request* msg, MultiLibLoader loader, size_t size = 1);
};
  void px_msgs_msg_pathRequest_common::copy_from_struct(px_msgs::path::Request* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
  }
  //----------------------------------------------------------------------------
  MDArray_T px_msgs_msg_pathRequest_common::get_arr(MDFactory_T& factory, const px_msgs::path::Request* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("px_msgs/pathRequest");
    }
    return std::move(outArray);
  }
class PX_MSGS_EXPORT px_msgs_msg_pathResponse_common : public MATLABROSMsgInterface<px_msgs::path::Response> {
  public:
    virtual ~px_msgs_msg_pathResponse_common(){}
    virtual void copy_from_struct(px_msgs::path::Response* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const px_msgs::path::Response* msg, MultiLibLoader loader, size_t size = 1);
};
  void px_msgs_msg_pathResponse_common::copy_from_struct(px_msgs::path::Response* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
  }
  //----------------------------------------------------------------------------
  MDArray_T px_msgs_msg_pathResponse_common::get_arr(MDFactory_T& factory, const px_msgs::path::Response* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("px_msgs/pathResponse");
    }
    return std::move(outArray);
  } 
class PX_MSGS_EXPORT px_msgs_path_service : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~px_msgs_path_service(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
    virtual std::shared_ptr<MATLABSvcServerInterface> generateSvcServerInterface();
    virtual std::shared_ptr<MATLABSvcClientInterface> generateSvcClientInterface();
};  
  std::shared_ptr<MATLABPublisherInterface> 
          px_msgs_path_service::generatePublisherInterface(ElementType type){
    std::shared_ptr<MATLABPublisherInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSPublisherImpl<px_msgs::path::Request,px_msgs_msg_pathRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSPublisherImpl<px_msgs::path::Response,px_msgs_msg_pathResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
  std::shared_ptr<MATLABSubscriberInterface> 
          px_msgs_path_service::generateSubscriberInterface(ElementType type){
    std::shared_ptr<MATLABSubscriberInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSSubscriberImpl<px_msgs::path::Request,px_msgs::path::Request::ConstPtr,px_msgs_msg_pathRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSSubscriberImpl<px_msgs::path::Response,px_msgs::path::Response::ConstPtr,px_msgs_msg_pathResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
  std::shared_ptr<MATLABSvcServerInterface> 
          px_msgs_path_service::generateSvcServerInterface(){
    return std::make_shared<ROSSvcServerImpl<px_msgs::path::Request,px_msgs::path::Response,px_msgs_msg_pathRequest_common,px_msgs_msg_pathResponse_common>>();
  }
  std::shared_ptr<MATLABSvcClientInterface> 
          px_msgs_path_service::generateSvcClientInterface(){
    return std::make_shared<ROSSvcClientImpl<px_msgs::path,px_msgs::path::Request,px_msgs::path::Response,px_msgs_msg_pathRequest_common,px_msgs_msg_pathResponse_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface> 
          px_msgs_path_service::generateRosbagWriterInterface(ElementType type){
    std::shared_ptr<MATLABRosbagWriterInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSBagWriterImpl<px_msgs::pathRequest,px_msgs_msg_pathRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSBagWriterImpl<px_msgs::pathResponse,px_msgs_msg_pathResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(px_msgs_msg_pathRequest_common, MATLABROSMsgInterface<px_msgs::pathRequest>)
CLASS_LOADER_REGISTER_CLASS(px_msgs_msg_pathResponse_common, MATLABROSMsgInterface<px_msgs::pathResponse>)
CLASS_LOADER_REGISTER_CLASS(px_msgs_path_service, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
