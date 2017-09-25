import sys

import matplotlib.pyplot as plt
import matplotlib.patches as mpatches


def graficarLog(log):
	s=990
	i=10
	v=0
	r=0
	S=[1000]
	I=[i]
	V=[v]
	R=[r]
	with open(log,'r') as registro:
		conteoInicial=True
		for line in registro:
			if conteoInicial:
				if "(b):lambda" in line:
					conteoInicial=False
			else:
				if "(e):got-infected" in line:
					s=s-1
					i=i+1
					S.append(1000)
					I.append(i+v+r)
					V.append(v+r)
					R.append(r)
				if "(e):got-vaccinated" in line:
					s=s-1
					v=v+1
					S.append(1000)
					I.append(i+v+r)
					V.append(v+r)
					R.append(r)
				if "(e):report-recovering" in line:
					r=r+1
					i=i-1
					S.append(1000)
					I.append(i+v+r)
					V.append(v+r)
					R.append(r)
	
	datos=len(S)
	x=range(datos)
	fig,ax=plt.subplots()
	ax.plot(x,S,x,I,x,V,x,R)
	ax.fill_between(x,S,I,facecolor='blue')
	ax.fill_between(x,I,V,facecolor='red')
	ax.fill_between(x,V,R,facecolor='green')
	ax.fill_between(x,R,0,facecolor='yellow')
	ax.axes.xaxis.set_ticklabels([])
	ax.set_xlim(0,datos)
	susceptibles= mpatches.Patch(color='blue', label='Susceptibles')
	infectados= mpatches.Patch(color='red', label='Infectados')
	vacunados=mpatches.Patch(color='green',label='Vacunados')
	recuperados=mpatches.Patch(color='yellow',label='Recuperados')
	ax.legend(handles=[susceptibles,infectados,vacunados,recuperados],loc=2)
	nombre=log.split('.')
	grafico=nombre[0]+nombre[2]
	plt.savefig(grafico)
	
log=sys.argv[1]	
graficarLog(log)
