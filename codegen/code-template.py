import sys
from jinja2 import Environment,FileSystemLoader 
if __name__ == '__main__':
	env = Environment(
	    loader=FileSystemLoader(sys.argv[1])
	)
	n = int(sys.argv[2])

	directory = "./" if len(sys.argv) == 2 else (sys.argv[3] + "/") 

	h_template = env.get_template('persona-template.h')

	for i in range(1,n+1):
		f = open(directory+"persona%d.h"%i,"w")
		vecinos = str(["S" for j in range(0,i)]).replace("'","").replace("[","{").replace("]","}")
		f.write(h_template.render(n=i,vecinos=vecinos))
		f.close()

	cpp_template = env.get_template('persona-template.cpp')

	for i in range(1,n+1):
		f = open(directory+"persona%d.cpp"%i,"w")
		f.write(cpp_template.render(n=i))
		f.close()
	
	reg_template = env.get_template('reg-template.cpp')
	f = open(directory+"reg.cpp","w")
	f.write(reg_template.render(n=n))
	f.close()

