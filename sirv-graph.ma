[top] //this represent the a <-> b <-> c graph, where b is initially infected
components : b@persona2 a@persona1 c@persona1
in : infect
link : infect infect@b
link : in0@b out0@a
link : in1@b out0@b
link : out0@b in0@a
link : out1@b in0@c