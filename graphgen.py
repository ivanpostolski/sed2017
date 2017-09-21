import random as rnd
import networkx as nx


def printma(CM,infect=[]):
	#prelude
	print "[top]"
	#components
	components = "components: "
	nodes = CM.nodes()
	for n in nodes:
		components += "node%d@persona%d " % (n,CM.degree(n))
	print components
	print "in: infect"
	for i in infect:
		print "link: infect infect@node%d" % i
	
	ports = [0 for i in range(0,len(nodes))]
	
	for edge in CM.edges():
		origin = edge[0]
		target = edge[1] 
		print "link: out%d@node%d in%d@node%d" % (ports[origin],origin,ports[target],target)
		print "link: in%d@node%d out%d@node%d" % (ports[origin],origin,ports[target],target)
		ports[origin] += 1
		ports[target] += 1


seq=[2,1,1]
G=nx.configuration_model(seq)
G.remove_edges_from(G.selfloop_edges())
G=nx.Graph(G)
printma(G,infect=[0])


