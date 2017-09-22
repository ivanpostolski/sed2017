import sys
import os

if __name__ == '__main__':
	for subdir, dirs, files in os.walk(sys.argv[1]):		
		for file in files:	 
			if "log" not in file:
				continue;
			print "Running sanity check in log file %s" % os.path.join(subdir, file)
			node_state = ['S' for i in range(1000)]
			with open(os.path.join(subdir, file)) as f:
				for line in f:
					if "(e):got-infected" in line:
						node = int(line.split("(")[0][4:][:-1])
						if node_state[node] == 'S':
							node_state[node] = 'PI'
						else:
							raise Exception("node%d was pre-infected but previous state was %s"%(node,node_state[node]))
					if "(e):pre-infected" in line:
						node = int(line.split("(")[0][4:])
						if node_state[node] == 'PI':
							node_state[node] = 'I'
						else:
							raise Exception("node%d was infected but previous state was %s"%(node,node_state[node]))

					if "(e):got-vaccinated" in line:
						node = int(line.split("(")[0][4:] 	)
						if node_state[node] == 'S':
							node_state[node] = 'V'
						else:
							raise Exception("node%d was vaccinated but previous state was %s"%(node,node_state[node]))
					if "(e):is-recovered" in line:
						node = int(line.split("(")[0][4:])
						if node_state[node] == 'I':
							node_state[node] = 'V'
						else:
							raise Exception("node%d was recovered but previous state was %s"%(node,node_state[node]))