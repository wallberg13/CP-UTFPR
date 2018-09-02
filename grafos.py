#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug 30 11:10:26 2018

@author: sir-berg
"""

from graphviz import Digraph

dot = Digraph(comment='Grafo de dependências Maratona-Linux')

dot.node('MD', 'maratona\ndesktop')
dot.node('ME', 'maratona\nessential',color='red:black')
dot.node('MF', 'maratona\nfirewall')
dot.node('MC', 'maratona\nconflitos')
dot.node('MB', 'maratona\nbackground')
dot.node('MU', 'maratona\nusuario\nicpc')
dot.node('MS', 'maratona\nsubmission')
dot.node('MEd', 'maratona\neditores')
dot.node('ML', 'maratona\nlinguagens',color='red:black')
dot.node('MLd', 'maratona\nlinguagens\ndoc',color='red:black')

dot.edge('MD','MF')
dot.edge('MD','MC')
dot.edge('MD','MB')
dot.edge('MD','MU')
dot.edge('MD','MS')
dot.edge('ME','MEd')
dot.edge('ME','ML')
dot.edge('ME','MLd')

dot.edge('MD','ME',color='red')
dot.edge('MEd','ML',color='red')
dot.edge('MU','MLd',color='red')

dot.format = 'svg'
#dot.view()
dot.render()

