function [data, info] = pedroPascal
%pedroPascal gives an empty data for px_msgs/pedroPascal
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'px_msgs/pedroPascal';
[data.Positions, info.Positions] = ros.internal.ros.messages.geometry_msgs.vector3;
info.Positions.MLdataType = 'struct';
info.Positions.MaxLen = NaN;
info.Positions.MinLen = 0;
data.Positions = data.Positions([],1);
info.MessageType = 'px_msgs/pedroPascal';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,4);
info.MatPath{1} = 'positions';
info.MatPath{2} = 'positions.x';
info.MatPath{3} = 'positions.y';
info.MatPath{4} = 'positions.z';
