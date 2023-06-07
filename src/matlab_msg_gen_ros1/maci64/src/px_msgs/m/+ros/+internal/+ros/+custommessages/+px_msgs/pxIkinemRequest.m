function [data, info] = pxIkinemRequest
%pxIkinem gives an empty data for px_msgs/pxIkinemRequest
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'px_msgs/pxIkinemRequest';
[data.Position, info.Position] = ros.internal.ros.messages.geometry_msgs.vector3;
info.Position.MLdataType = 'struct';
info.MessageType = 'px_msgs/pxIkinemRequest';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,4);
info.MatPath{1} = 'position';
info.MatPath{2} = 'position.x';
info.MatPath{3} = 'position.y';
info.MatPath{4} = 'position.z';
