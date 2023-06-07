// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for px_msgs/pxConfigVector
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
#include "px_msgs/pxConfigVector.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class PX_MSGS_EXPORT px_msgs_msg_pxConfigVector_common : public MATLABROSMsgInterface<px_msgs::pxConfigVector> {
  public:
    virtual ~px_msgs_msg_pxConfigVector_common(){}
    virtual void copy_from_struct(px_msgs::pxConfigVector* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const px_msgs::pxConfigVector* msg, MultiLibLoader loader, size_t size = 1);
};
  void px_msgs_msg_pxConfigVector_common::copy_from_struct(px_msgs::pxConfigVector* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //q1
        const matlab::data::TypedArray<double> q1_arr = arr["Q1"];
        msg->q1 = q1_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Q1' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Q1' is wrong type; expected a double.");
    }
    try {
        //q2
        const matlab::data::TypedArray<double> q2_arr = arr["Q2"];
        msg->q2 = q2_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Q2' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Q2' is wrong type; expected a double.");
    }
    try {
        //q3
        const matlab::data::TypedArray<double> q3_arr = arr["Q3"];
        msg->q3 = q3_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Q3' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Q3' is wrong type; expected a double.");
    }
    try {
        //q4
        const matlab::data::TypedArray<double> q4_arr = arr["Q4"];
        msg->q4 = q4_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Q4' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Q4' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T px_msgs_msg_pxConfigVector_common::get_arr(MDFactory_T& factory, const px_msgs::pxConfigVector* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Q1","Q2","Q3","Q4"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("px_msgs/pxConfigVector");
    // q1
    auto currentElement_q1 = (msg + ctr)->q1;
    outArray[ctr]["Q1"] = factory.createScalar(currentElement_q1);
    // q2
    auto currentElement_q2 = (msg + ctr)->q2;
    outArray[ctr]["Q2"] = factory.createScalar(currentElement_q2);
    // q3
    auto currentElement_q3 = (msg + ctr)->q3;
    outArray[ctr]["Q3"] = factory.createScalar(currentElement_q3);
    // q4
    auto currentElement_q4 = (msg + ctr)->q4;
    outArray[ctr]["Q4"] = factory.createScalar(currentElement_q4);
    }
    return std::move(outArray);
  } 
class PX_MSGS_EXPORT px_msgs_pxConfigVector_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~px_msgs_pxConfigVector_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          px_msgs_pxConfigVector_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<px_msgs::pxConfigVector,px_msgs_msg_pxConfigVector_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         px_msgs_pxConfigVector_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<px_msgs::pxConfigVector,px_msgs::pxConfigVector::ConstPtr,px_msgs_msg_pxConfigVector_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         px_msgs_pxConfigVector_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<px_msgs::pxConfigVector,px_msgs_msg_pxConfigVector_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(px_msgs_msg_pxConfigVector_common, MATLABROSMsgInterface<px_msgs::pxConfigVector>)
CLASS_LOADER_REGISTER_CLASS(px_msgs_pxConfigVector_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1