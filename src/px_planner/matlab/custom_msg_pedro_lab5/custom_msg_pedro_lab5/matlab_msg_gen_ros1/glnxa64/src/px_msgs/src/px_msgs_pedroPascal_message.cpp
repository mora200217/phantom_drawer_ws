// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for px_msgs/pedroPascal
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
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif //_MSC_VER
#include "ros/ros.h"
#include "px_msgs/pedroPascal.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class PX_MSGS_EXPORT px_msgs_msg_pedroPascal_common : public MATLABROSMsgInterface<px_msgs::pedroPascal> {
  public:
    virtual ~px_msgs_msg_pedroPascal_common(){}
    virtual void copy_from_struct(px_msgs::pedroPascal* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const px_msgs::pedroPascal* msg, MultiLibLoader loader, size_t size = 1);
};
  void px_msgs_msg_pedroPascal_common::copy_from_struct(px_msgs::pedroPascal* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //positions
        const matlab::data::StructArray positions_arr = arr["Positions"];
        for (auto _positionsarr : positions_arr) {
        	geometry_msgs::Vector3 _val;
        auto msgClassPtr_positions = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_positions->copy_from_struct(&_val,_positionsarr,loader);
        	msg->positions.push_back(_val);
        }
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Positions' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Positions' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T px_msgs_msg_pedroPascal_common::get_arr(MDFactory_T& factory, const px_msgs::pedroPascal* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Positions"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("px_msgs/pedroPascal");
    // positions
    auto currentElement_positions = (msg + ctr)->positions;
    auto msgClassPtr_positions = getCommonObject<geometry_msgs::Vector3>("geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["Positions"] = msgClassPtr_positions->get_arr(factory,&currentElement_positions[0],loader,currentElement_positions.size());
    }
    return std::move(outArray);
  } 
class PX_MSGS_EXPORT px_msgs_pedroPascal_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~px_msgs_pedroPascal_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          px_msgs_pedroPascal_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<px_msgs::pedroPascal,px_msgs_msg_pedroPascal_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         px_msgs_pedroPascal_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<px_msgs::pedroPascal,px_msgs::pedroPascal::ConstPtr,px_msgs_msg_pedroPascal_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         px_msgs_pedroPascal_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<px_msgs::pedroPascal,px_msgs_msg_pedroPascal_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(px_msgs_msg_pedroPascal_common, MATLABROSMsgInterface<px_msgs::pedroPascal>)
CLASS_LOADER_REGISTER_CLASS(px_msgs_pedroPascal_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1