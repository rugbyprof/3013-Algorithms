#!/usr/bin/python3
import sys
import math


sys.path.append("/usr/local/lib/python3.7/site-packages")
from scipy import special
import plotly
import plotly.graph_objects as go
import numpy as np

title = "Complexity"
labels = ["Log N", "N", "N Log N", "N^2", "N^3"]
colors = [
    "rgb(67,67,67)",
    "rgb(115,115,115)",
    "rgb(49,130,189)",
    "rgb(189,189,189)",
    "rgb(189,189,189)",
]

size = 10
x = np.array([x for x in range(1, size + 1)])
y = np.array([y for y in range(1, size + 1)])

fig = go.Figure()


fig.add_trace(go.Scatter(x=x, y=np.log2(x), name="log N"))
fig.add_trace(go.Scatter(x=x, y=x, name="N"))
fig.add_trace(go.Scatter(x=x, y=np.log2(x) * x, name="N log N"))
fig.add_trace(go.Scatter(x=x, y=pow(x, 2), name="N^2"))
fig.add_trace(go.Scatter(x=x, y=pow(x, 3), name="N^3"))
fig.add_trace(go.Scatter(x=x, y=special.factorial(x), name="N!"))

fig.update_traces(hoverinfo="text+name", mode="lines+markers")
fig.update_layout(legend=dict(y=0.5, traceorder="reversed", font_size=16))

fig.show()
plotly.offline.plot(fig, filename="complexity.html", auto_open=False)
