
classdef ikinemRequest < ros.Message
    %ikinemRequest MATLAB implementation of px_msgs/ikinemRequest
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'px_msgs/ikinemRequest' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = '0d631cf7c1cba9ce4129d782fefeb82d' % The MD5 Checksum of the message definition
        PropertyList = { 'DesiredPosition' } % List of non-constant message properties
        ROSPropertyList = { 'desiredPosition' } % List of non-constant ROS message properties
        PropertyMessageTypes = { 'ros.msggen.geometry_msgs.Vector3' ...
            } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        DesiredPosition
    end
    methods
        function set.DesiredPosition(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.geometry_msgs.Vector3'};
            validateattributes(val, validClasses, validAttributes, 'ikinemRequest', 'DesiredPosition')
            obj.DesiredPosition = val;
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.px_msgs.ikinemRequest.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.px_msgs.ikinemRequest(strObj);
        end
    end
end
