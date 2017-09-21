import random as rnd
import networkx as nx
from networkx.utils import uniform_sequence, create_degree_sequence
import sys



def printma(CM,infect=[]):
	#prelude
	print "[top]"
	#components
	components = "components: "
	nodes = CM.nodes()
	for n in nodes:
		components += "node%d@persona%d " % (n,CM.degree(n) if CM.degree(n) > 0 else 1)
	print components
	print "in: infect"
	for i in infect:
		print "link: infect infect@node%d" % i
	
	ports = [0 for i in range(0,len(nodes))]
	
	for edge in CM.edges():
		origin = edge[0]
		target = edge[1] 
		print "link: out%d@node%d in%d@node%d" % (ports[origin],origin,ports[target],target)
		print "link: out%d@node%d in%d@node%d" % (ports[target],target,ports[origin],origin)
		ports[origin] += 1
		ports[target] += 1

if (len(sys.argv) < 2):
	print "arg[0] is population size, arg[1] is gamma alpha (default 10), arg[2] is beta (default 1) and arg[3] is infected size (default 1%)"
	sys.exit(0);
n = int(sys.argv[1])
seq=create_degree_sequence(n,lambda x: [rnd.gammavariate(alpha=10.0 if len(sys.argv) < 3 else float(sys.argv[2]) ,beta=1.0 if len(sys.argv) < 4 else float(sys.argv[3])) for i in range(x)])
G=nx.configuration_model(seq)
G.remove_edges_from(G.selfloop_edges())
G=nx.Graph(G)
degree_sequence=sorted(nx.degree(G).values(),reverse=True) # degree sequence
print "%Degree sequence is ", degree_sequence
dmax=max(degree_sequence)
print "%%Max degree is: %d"%dmax
printma(G,infect=[rnd.randint(0,n-1) for i in range(n/100 if len(sys.argv) < 5 else int(sys.argv[4]))])


