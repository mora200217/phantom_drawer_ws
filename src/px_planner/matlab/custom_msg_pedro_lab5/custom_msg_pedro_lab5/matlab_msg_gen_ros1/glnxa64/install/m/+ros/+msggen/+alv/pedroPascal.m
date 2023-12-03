
classdef pedroPascal < ros.Message
    %pedroPascal MATLAB implementation of alv/pedroPascal
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'alv/pedroPascal' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = '2683d6a07869c87203975100587e103c' % The MD5 Checksum of the message definition
        PropertyList = { 'Positions' 'X' 'Y' 'Z' } % List of non-constant message properties
        ROSPropertyList = { 'positions' 'x' 'y' 'z' } % List of non-constant ROS message properties
        PropertyMessageTypes = { 'ros.msggen.geometry_msgs.Vector3' ...
            '' ...
            '' ...
            '' ...
            } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        Positions
        X
        Y
        Z
    end
    methods
        function set.Positions(obj, val)
            if isempty(val)
                % Allow empty [] input
                val = ros.msggen.geometry_msgs.Vector3.empty(0, 1);
            end
            val = val(:);
            validAttributes = {'vector'};
            validClasses = {'ros.msggen.geometry_msgs.Vector3'};
            validateattributes(val, validClasses, validAttributes, 'pedroPascal', 'Positions')
            obj.Positions = val;
        end
        function set.X(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'pedroPascal', 'X');
            obj.X = double(val);
        end
        function set.Y(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'pedroPascal', 'Y');
            obj.Y = double(val);
        end
        function set.Z(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'pedroPascal', 'Z');
            obj.Z = double(val);
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.alv.pedroPascal.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.alv.pedroPascal(strObj);
        end
    end
end