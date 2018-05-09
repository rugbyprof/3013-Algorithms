<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>3013_Hash_Test2_sol_sp.18</title>
  <link rel="stylesheet" href="https://stackedit.io/style.css" />
</head>

<body class="stackedit">
  <div class="stackedit__html"><h3 id="question-1">Question 1</h3>
<p>Draw 3 separate hash tables that results from using a given hash function (below) to hash a given set of keys using the following collision resolution techniques:<br>
<strong>1)</strong> linear probing <strong>2)</strong> double hashing <strong>3)</strong> chaining</p>

<table>
<thead>
<tr>
<th align="center"></th>
<th align="center">Hash Functions</th>
<th align="center"></th>
</tr>
</thead>
<tbody>
<tr>
<td align="center">1</td>
<td align="center"><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>h</mi><mn>1</mn><mo>(</mo><mi>k</mi><mo>)</mo><mo>=</mo><mo fence="false">(</mo><munderover><mo>∑</mo><mrow><mi>i</mi><mo>=</mo><mn>0</mn></mrow><mrow><mi>s</mi><mi mathvariant="normal">.</mi><mi>l</mi><mi>e</mi><mi>n</mi><mi>g</mi><mi>t</mi><mi>h</mi><mo>(</mo><mo>)</mo><mo>−</mo><mn>1</mn></mrow></munderover><mrow><mi>A</mi><mi>s</mi><mi>c</mi><mi>i</mi><mi>i</mi><mo>(</mo><mi>s</mi><mo>[</mo><mi>i</mi><mo>]</mo><mo>)</mo></mrow><mo fence="false">)</mo><mrow><mi mathvariant="normal">%</mi><mtext>&nbsp;</mtext><mi>T</mi><mi>a</mi><mi>b</mi><mi>l</mi><mi>e</mi><mi>S</mi><mi>i</mi><mi>z</mi><mi>e</mi></mrow></mrow><annotation encoding="application/x-tex">h1(k) = \bigg (\sum_{i=0}^{s.length()-1} {Ascii(s[i]) } \bigg) {\%  \ TableSize} </annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 1.96101em;"></span><span class="strut bottom" style="height: 3.23867em; vertical-align: -1.27767em;"></span><span class="base"><span class="mord mathit">h</span><span class="mord mathrm">1</span><span class="mopen">(</span><span class="mord mathit" style="margin-right: 0.03148em;">k</span><span class="mclose">)</span><span class="mrel">=</span><span class="mord"><span class="delimsizing size3">(</span></span><span class="mop op-limits"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 1.96101em;"><span class="" style="top: -1.87233em; margin-left: 0em;"><span class="pstrut" style="height: 3.05em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathit mtight">i</span><span class="mrel mtight">=</span><span class="mord mathrm mtight">0</span></span></span></span><span class="" style="top: -3.05001em;"><span class="pstrut" style="height: 3.05em;"></span><span class=""><span class="mop op-symbol large-op">∑</span></span></span><span class="" style="top: -4.386em; margin-left: 0em;"><span class="pstrut" style="height: 3.05em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathit mtight">s</span><span class="mord mathrm mtight">.</span><span class="mord mathit mtight" style="margin-right: 0.01968em;">l</span><span class="mord mathit mtight">e</span><span class="mord mathit mtight">n</span><span class="mord mathit mtight" style="margin-right: 0.03588em;">g</span><span class="mord mathit mtight">t</span><span class="mord mathit mtight">h</span><span class="mopen mtight">(</span><span class="mclose mtight">)</span><span class="mbin mtight">−</span><span class="mord mathrm mtight">1</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 1.27767em;"></span></span></span></span><span class="mord"><span class="mord mathit">A</span><span class="mord mathit">s</span><span class="mord mathit">c</span><span class="mord mathit">i</span><span class="mord mathit">i</span><span class="mopen">(</span><span class="mord mathit">s</span><span class="mopen">[</span><span class="mord mathit">i</span><span class="mclose">]</span><span class="mclose">)</span></span><span class="mord"><span class="delimsizing size3">)</span></span><span class="mord"><span class="mord mathrm">%</span><span class="mord mathit"><span class="mspace">&nbsp;</span><span class="mord mathit" style="margin-right: 0.13889em;">T</span></span><span class="mord mathit">a</span><span class="mord mathit">b</span><span class="mord mathit" style="margin-right: 0.01968em;">l</span><span class="mord mathit">e</span><span class="mord mathit" style="margin-right: 0.05764em;">S</span><span class="mord mathit">i</span><span class="mord mathit" style="margin-right: 0.04398em;">z</span><span class="mord mathit">e</span></span></span></span></span></span></span></td>
<td align="center">or the sum of the ascii value of each letter mod table size</td>
</tr>
<tr>
<td align="center">2</td>
<td align="center"><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>h</mi><mn>2</mn><mo>(</mo><mi>k</mi><mo>)</mo><mo>=</mo><mo>(</mo><mi>h</mi><mn>1</mn><mo>(</mo><mi>k</mi><mo>)</mo><mo>∗</mo><mi>i</mi><mo>)</mo><mtext>&nbsp;</mtext><mi mathvariant="normal">%</mi><mtext>&nbsp;</mtext><mi>T</mi><mi>a</mi><mi>b</mi><mi>l</mi><mi>e</mi><mi>S</mi><mi>i</mi><mi>z</mi><mi>e</mi></mrow><annotation encoding="application/x-tex"> h2(k) = (h1(k) * i)\ \% \ TableSize </annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.75em;"></span><span class="strut bottom" style="height: 1em; vertical-align: -0.25em;"></span><span class="base"><span class="mord mathit">h</span><span class="mord mathrm">2</span><span class="mopen">(</span><span class="mord mathit" style="margin-right: 0.03148em;">k</span><span class="mclose">)</span><span class="mrel">=</span><span class="mopen">(</span><span class="mord mathit">h</span><span class="mord mathrm">1</span><span class="mopen">(</span><span class="mord mathit" style="margin-right: 0.03148em;">k</span><span class="mclose">)</span><span class="mbin">∗</span><span class="mord mathit">i</span><span class="mclose">)</span><span class="mord mathrm"><span class="mspace">&nbsp;</span><span class="mord mathrm">%</span></span><span class="mord mathit"><span class="mspace">&nbsp;</span><span class="mord mathit" style="margin-right: 0.13889em;">T</span></span><span class="mord mathit">a</span><span class="mord mathit">b</span><span class="mord mathit" style="margin-right: 0.01968em;">l</span><span class="mord mathit">e</span><span class="mord mathit" style="margin-right: 0.05764em;">S</span><span class="mord mathit">i</span><span class="mord mathit" style="margin-right: 0.04398em;">z</span><span class="mord mathit">e</span></span></span></span></span></span></td>
<td align="center">where <em>i</em> is the <em>i<sup>th</sup></em>  collision + 1</td>
</tr>
</tbody>
</table><h4 id="strings-to-hash">Strings to Hash</h4>
<blockquote>
<p><strong>Epd, DcS, Fcf, Gco, Qzj, Wvc, RUC, ejJ, iwR, zyz</strong></p>
</blockquote>
<h4 id="answer">Answer:</h4>
<pre><code>Epd = 281 % 11 = 6  
DcS = 250 % 11 = 8  
Fcf = 271 % 11 = 7  
Gco = 281 % 11 = 6  
Qzj = 309 % 11 = 1  
Wvc = 304 % 11 = 7  
RUC = 234 % 11 = 3  
ejJ = 281 % 11 = 6  
iwR = 306 % 11 = 9  
zyz = 365 % 11 = 2
</code></pre>

<table>
<thead>
<tr>
<th align="center">Ascii</th>
<th align="center">Linear Probing</th>
<th align="center">Double Hashing</th>
<th align="center">Chaining</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center"><img src="https://d3vv6lp55qjaqc.cloudfront.net/items/33200j3p390V2T0N0n39/Screen%20Shot%202018-04-17%20at%202.33.22%20PM.png" alt=""></td>
<td align="center"><img src="https://d3vv6lp55qjaqc.cloudfront.net/items/3d1K2x0P0f013B0j3g17/Screen%20Shot%202018-04-19%20at%207.00.53%20AM.png" alt=""></td>
<td align="center"><img src="https://d3vv6lp55qjaqc.cloudfront.net/items/1O1A3N3V0f3V3F1q3z2n/Screen%20Shot%202018-04-19%20at%207.01.30%20AM.png" alt=""></td>
<td align="center"><img src="https://d3vv6lp55qjaqc.cloudfront.net/items/1J0L180d2C0Y0n2f3Z2h/Screen%20Shot%202018-04-19%20at%207.02.41%20AM.png" alt=""></td>
</tr>
</tbody>
</table><hr>
<h3 id="question-2">Question 2</h3>
<p><strong>Given:</strong>  A hash table that uses linear probing to handle collisions.<br>
<strong>Describe Problem:</strong> Describe a situation in which searching for a value in this hash table you might not find the value, even though it is in the table.<br>
<strong>Propose Solution:</strong> Describe a solution for this problem.</p>
<blockquote>
<p><strong>Answer:</strong><br>
<strong>Problem:</strong> When clustering occurs in an open addressed hash table, and a subsequent delete occurs in the middle of the cluster, a search may discover the empty slot and terminate the search.<br>
<strong>Solution:</strong> After an item is deleted from a hash table, mark it with a special value showing that this cell was previously occupied and had a deleted value. Then the search can continue.</p>
</blockquote>
<hr>
<h3 id="question-3">Question 3</h3>
<p><strong>Problem:</strong> A hash table is having trouble with clustering.<br>
<strong>Describe:</strong></p>

<table>
<thead>
<tr>
<th></th>
<th></th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>A.</strong></td>
<td>What is clustering?</td>
</tr>
<tr>
<td><strong>B.</strong></td>
<td>What type of collision resolution does this typically occur with?</td>
</tr>
<tr>
<td><strong>C.</strong></td>
<td>What is the generic solution to the clustering problem? Your answer shouldn’t just be: “use new hash function”. It should be discussed using general terms and definitions.</td>
</tr>
</tbody>
</table><p><strong>Answer:</strong></p>

<table>
<thead>
<tr>
<th></th>
<th></th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>A.</strong></td>
<td>The grouping of hashed values in an open addressed hash table due to a hash function creating hash keys that either collide or are very close to other hashed values.  Clustering is NOT simply a bunch of hashed values close to each other.</td>
</tr>
<tr>
<td><strong>B.</strong></td>
<td>Linear Probing</td>
</tr>
<tr>
<td><strong>C.</strong></td>
<td>Change your <code>probe increment</code> so that it skips over differing sizes preferably sizes that are <code>relatively prime</code> to the table size.</td>
</tr>
</tbody>
</table><hr>
<h3 id="question-4">Question 4</h3>
<p><strong>Given:</strong> The formula for unsuccessful search in a hash table is: <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>O</mi><mo>(</mo><mfrac><mrow><mn>1</mn></mrow><mrow><mn>1</mn><mo>−</mo><mi>λ</mi></mrow></mfrac><mo>)</mo></mrow><annotation encoding="application/x-tex">O(\frac{1}{1-\lambda})</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.845108em;"></span><span class="strut bottom" style="height: 1.24844em; vertical-align: -0.403331em;"></span><span class="base"><span class="mord mathit" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.845108em;"><span class="" style="top: -2.655em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathrm mtight">1</span><span class="mbin mtight">−</span><span class="mord mathit mtight">λ</span></span></span></span><span class="" style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line hide-tail" style="height: 0.04em;"><svg width="400em" height="400em" viewBox="0 0 400000 400000" preserveAspectRatio="xMinYMin slice"><path d="M0 0 h400000 v400000 h-400000z M0 0 h400000 v400000 h-400000z"></path></svg></span></span><span class="" style="top: -3.394em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathrm mtight">1</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.403331em;"></span></span></span></span><span class="mclose nulldelimiter"></span></span><span class="mclose">)</span></span></span></span></span><br>
<strong>Describe:</strong> The time for searches increases as the load factor increases. Explain why this happens as described in our study guide.</p>
<blockquote>
<p><strong>Answer:</strong></p>
<ul>
<li>As <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>n</mi></mrow><annotation encoding="application/x-tex">n</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.43056em;"></span><span class="strut bottom" style="height: 0.43056em; vertical-align: 0em;"></span><span class="base"><span class="mord mathit">n</span></span></span></span></span> gets closer to <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>M</mi></mrow><annotation encoding="application/x-tex">M</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.68333em;"></span><span class="strut bottom" style="height: 0.68333em; vertical-align: 0em;"></span><span class="base"><span class="mord mathit" style="margin-right: 0.10903em;">M</span></span></span></span></span>,  <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>λ</mi></mrow><annotation encoding="application/x-tex">\lambda</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.69444em;"></span><span class="strut bottom" style="height: 0.69444em; vertical-align: 0em;"></span><span class="base"><span class="mord mathit">λ</span></span></span></span></span> gets closer to 1,</li>
<li>so <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mn>1</mn><mo>−</mo><mi>λ</mi></mrow><annotation encoding="application/x-tex">1-\lambda</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.69444em;"></span><span class="strut bottom" style="height: 0.77777em; vertical-align: -0.08333em;"></span><span class="base"><span class="mord mathrm">1</span><span class="mbin">−</span><span class="mord mathit">λ</span></span></span></span></span> gets closer to <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mn>0</mn></mrow><annotation encoding="application/x-tex">0</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.64444em;"></span><span class="strut bottom" style="height: 0.64444em; vertical-align: 0em;"></span><span class="base"><span class="mord mathrm">0</span></span></span></span></span>,</li>
<li>so <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mfrac><mrow><mn>1</mn></mrow><mrow><mn>1</mn><mo>−</mo><mi>λ</mi></mrow></mfrac></mrow><annotation encoding="application/x-tex">\frac{1}{1-\lambda}</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.845108em;"></span><span class="strut bottom" style="height: 1.24844em; vertical-align: -0.403331em;"></span><span class="base"><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.845108em;"><span class="" style="top: -2.655em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathrm mtight">1</span><span class="mbin mtight">−</span><span class="mord mathit mtight">λ</span></span></span></span><span class="" style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line hide-tail" style="height: 0.04em;"><svg width="400em" height="400em" viewBox="0 0 400000 400000" preserveAspectRatio="xMinYMin slice"><path d="M0 0 h400000 v400000 h-400000z M0 0 h400000 v400000 h-400000z"></path></svg></span></span><span class="" style="top: -3.394em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathrm mtight">1</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.403331em;"></span></span></span></span><span class="mclose nulldelimiter"></span></span></span></span></span></span> gets larger.</li>
</ul>
<p>At the extreme, when <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>n</mi><mo>=</mo><mi>M</mi><mo>−</mo><mn>1</mn></mrow><annotation encoding="application/x-tex">n = M - 1</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.68333em;"></span><span class="strut bottom" style="height: 0.76666em; vertical-align: -0.08333em;"></span><span class="base"><span class="mord mathit">n</span><span class="mrel">=</span><span class="mord mathit" style="margin-right: 0.10903em;">M</span><span class="mbin">−</span><span class="mord mathrm">1</span></span></span></span></span>, the formula <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mfrac><mrow><mn>1</mn></mrow><mrow><mn>1</mn><mo>−</mo><mi>λ</mi></mrow></mfrac><mo>=</mo><mi>M</mi></mrow><annotation encoding="application/x-tex">\frac{1}{1-\lambda} = M</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.845108em;"></span><span class="strut bottom" style="height: 1.24844em; vertical-align: -0.403331em;"></span><span class="base"><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.845108em;"><span class="" style="top: -2.655em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathrm mtight">1</span><span class="mbin mtight">−</span><span class="mord mathit mtight">λ</span></span></span></span><span class="" style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line hide-tail" style="height: 0.04em;"><svg width="400em" height="400em" viewBox="0 0 400000 400000" preserveAspectRatio="xMinYMin slice"><path d="M0 0 h400000 v400000 h-400000z M0 0 h400000 v400000 h-400000z"></path></svg></span></span><span class="" style="top: -3.394em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathrm mtight">1</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.403331em;"></span></span></span></span><span class="mclose nulldelimiter"></span></span><span class="mrel">=</span><span class="mord mathit" style="margin-right: 0.10903em;">M</span></span></span></span></span>, meaning that you will search the entire table before discovering that the key is not there. In laymen’s terms, this means there are less open slots to terminate a search.</p>
<p>Note: A larger load factor does NOT necessarily imply more collisions. A perfect hash will have zero collisions and eventually have a load factor of 1. The real problem is that when the load factor increases, the number of contiguous memory locations increases as well. When a key is being search for, it must traverse these longer contiguous memory chunks until eventually searching the entire table when the load factor = 1.</p>
</blockquote>
<hr>
<h3 id="question-5">Question 5</h3>
<p><strong>Problem:</strong> What decides whether a hash function will perform well or not? In other words, how would you benchmark a hash function.<br>
<strong>Proposed Solution:</strong> Discuss <code>input data</code>, <code>load factor</code>, <code>collisions</code>, <code>collision resolution</code>.</p>
<blockquote>
<p><strong>Answer:</strong></p>
<p><strong>Some Definitions:</strong></p>
<p><a href="http://en.wikipedia.org/wiki/Benchmark_%28computing%29" title="Benchmark (computing)">Benchmark (computing)</a>, the result of running a computer program, or a set of programs, in order to assess the relative performance of an object by running a number of standard tests and trials against it.</p>
<ul>
<li><strong>Input data</strong><br>
-   The data being hashed has an impact on the choice of hash function.<br>
-   Data that is similar or short in length could create a smaller range of hash keys, increasing collisions.</li>
<li><strong>Load Factor</strong><br>
-   The ratio of the number of records to the number of addresses or indexes within a data structure.<br>
-   Effected by choice of table size.</li>
<li><strong>Table Size</strong><br>
-   Poor choice in table size (to small) has a direct effect on load factor.<br>
-   A full table is, well…… a huge cost to rehash all those values. There are some alternatives not discussed in class to table resizing<br>
-   To large of a table is a simple waste of resources.<br>
-   Prime numbers not close to a power of two</li>
<li><strong>Collision Resolution</strong><br>
-   Chaining vs open addressing (as well as many others)</li>
</ul>
<p><strong>Expected Answer:</strong></p>
<p>Benchmarking a hash function is not very difficult at all. By looking at the factors that determine a hash functions performance, (terms above), we could easily create a test that would objectively quantify a hash functions performance. <strong>1)</strong> use various forms of input data for reasons described above. <strong>2)</strong> Choose various table sizes. <strong>3)</strong> Choose different types of collision resolution techniques.</p>
<p>After all the parameters are chosen, implement each of these parameters using various configurations, all the while counting the percentage of collisions and average # of comparisons to retrieve a value (could be determined from collision ratio).  Some of the performance could be effected by the computers hardware and type of collision resolution chosen. Cpu speed and cache size could (obviously) effect speed of the calculated hash key, as well as retrieval.</p>
</blockquote>
<h3 id="question-6">Question 6</h3>
<p><strong>Problem:</strong> Consider a hash table where <code>collisions</code> are resolved with <code>chaining</code>.<br>
<strong>Describe:</strong> Under what conditions do the operations of insert, search and delete take constant expected time?</p>
<blockquote>
<p><strong>Answer:</strong></p>
<p><strong>Remember:</strong> <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mrow><mi>λ</mi><mo>=</mo><mo>(</mo><mi>n</mi><mi mathvariant="normal">/</mi><mi>M</mi><mo>)</mo></mrow></mrow><annotation encoding="application/x-tex">{ \lambda = (n / M)}</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.75em;"></span><span class="strut bottom" style="height: 1em; vertical-align: -0.25em;"></span><span class="base"><span class="mord"><span class="mord mathit">λ</span><span class="mrel">=</span><span class="mopen">(</span><span class="mord mathit">n</span><span class="mord mathrm">/</span><span class="mord mathit" style="margin-right: 0.10903em;">M</span><span class="mclose">)</span></span></span></span></span></span>  <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mo>[</mo><mi>M</mi></mrow><annotation encoding="application/x-tex">[M</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.75em;"></span><span class="strut bottom" style="height: 1em; vertical-align: -0.25em;"></span><span class="base"><span class="mopen">[</span><span class="mord mathit" style="margin-right: 0.10903em;">M</span></span></span></span></span> = Table Size and <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>n</mi></mrow><annotation encoding="application/x-tex">n</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.43056em;"></span><span class="strut bottom" style="height: 0.43056em; vertical-align: 0em;"></span><span class="base"><span class="mord mathit">n</span></span></span></span></span> = items inserted <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mo>]</mo></mrow><annotation encoding="application/x-tex">]</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.75em;"></span><span class="strut bottom" style="height: 1em; vertical-align: -0.25em;"></span><span class="base"><span class="mclose">]</span></span></span></span></span></p>
<p>Chains average: <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>O</mi><mo>(</mo><mn>1</mn><mo>+</mo><mi>λ</mi><mo>)</mo></mrow><annotation encoding="application/x-tex">O(1 + \lambda)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.75em;"></span><span class="strut bottom" style="height: 1em; vertical-align: -0.25em;"></span><span class="base"><span class="mord mathit" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathrm">1</span><span class="mbin">+</span><span class="mord mathit">λ</span><span class="mclose">)</span></span></span></span></span>.  If <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>λ</mi></mrow><annotation encoding="application/x-tex">\lambda</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.69444em;"></span><span class="strut bottom" style="height: 0.69444em; vertical-align: 0em;"></span><span class="base"><span class="mord mathit">λ</span></span></span></span></span> is small enough , we can guarantee that <strong>on average</strong> all of the above operations will average out to be <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>O</mi><mo>(</mo><mn>1</mn><mo>)</mo></mrow><annotation encoding="application/x-tex">O(1)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.75em;"></span><span class="strut bottom" style="height: 1em; vertical-align: -0.25em;"></span><span class="base"><span class="mord mathit" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathrm">1</span><span class="mclose">)</span></span></span></span></span>. Because in the computer science world, <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>c</mi><mi>o</mi><mi>n</mi><mi>s</mi><mi>t</mi><mi>a</mi><mi>n</mi><mi>t</mi><mtext>&nbsp;</mtext><mi>t</mi><mi>i</mi><mi>m</mi><mi>e</mi><mo>=</mo><mi>O</mi><mo>(</mo><mn>1</mn><mo>)</mo></mrow><annotation encoding="application/x-tex">constant\ time = O(1)</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.75em;"></span><span class="strut bottom" style="height: 1em; vertical-align: -0.25em;"></span><span class="base"><span class="mord mathit">c</span><span class="mord mathit">o</span><span class="mord mathit">n</span><span class="mord mathit">s</span><span class="mord mathit">t</span><span class="mord mathit">a</span><span class="mord mathit">n</span><span class="mord mathit">t</span><span class="mord mathit"><span class="mspace">&nbsp;</span><span class="mord mathit">t</span></span><span class="mord mathit">i</span><span class="mord mathit">m</span><span class="mord mathit">e</span><span class="mrel">=</span><span class="mord mathit" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathrm">1</span><span class="mclose">)</span></span></span></span></span>.</p>
<p><strong>However:</strong><br>
If <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>λ</mi></mrow><annotation encoding="application/x-tex">\lambda</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.69444em;"></span><span class="strut bottom" style="height: 0.69444em; vertical-align: 0em;"></span><span class="base"><span class="mord mathit">λ</span></span></span></span></span>  starts getting close to 1 or larger than 1, then some constant <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>C</mi></mrow><annotation encoding="application/x-tex">C</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.68333em;"></span><span class="strut bottom" style="height: 0.68333em; vertical-align: 0em;"></span><span class="base"><span class="mord mathit" style="margin-right: 0.07153em;">C</span></span></span></span></span>, is expected <strong>for all conditions</strong>. Where the size of <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>C</mi></mrow><annotation encoding="application/x-tex">C</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.68333em;"></span><span class="strut bottom" style="height: 0.68333em; vertical-align: 0em;"></span><span class="base"><span class="mord mathit" style="margin-right: 0.07153em;">C</span></span></span></span></span>  is determined by the performance of our hash function and ultimately the load factor (<span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>λ</mi></mrow><annotation encoding="application/x-tex">\lambda</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.69444em;"></span><span class="strut bottom" style="height: 0.69444em; vertical-align: 0em;"></span><span class="base"><span class="mord mathit">λ</span></span></span></span></span>) of the table. <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>C</mi></mrow><annotation encoding="application/x-tex">C</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.68333em;"></span><span class="strut bottom" style="height: 0.68333em; vertical-align: 0em;"></span><span class="base"><span class="mord mathit" style="margin-right: 0.07153em;">C</span></span></span></span></span> would be equal to the longest chain in the table.  But the average length of each list would be  equal to  <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>λ</mi></mrow><annotation encoding="application/x-tex">\lambda</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.69444em;"></span><span class="strut bottom" style="height: 0.69444em; vertical-align: 0em;"></span><span class="base"><span class="mord mathit">λ</span></span></span></span></span>.  So even though we might not achieve “constant” time, worst case performance is still <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mo>&lt;</mo><mo>=</mo><mi>C</mi></mrow><annotation encoding="application/x-tex">&lt;= C</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.68333em;"></span><span class="strut bottom" style="height: 0.72243em; vertical-align: -0.0391em;"></span><span class="base"><span class="mrel">&lt;</span><span class="mrel">=</span><span class="mord mathit" style="margin-right: 0.07153em;">C</span></span></span></span></span>.</p>
</blockquote>
<hr>
<h3 id="question-7">Question 7</h3>
<p><strong>Describe:</strong> Why is using <code>polynomial hashing</code> on strings preferable to a hash code that simply sums up the ASCII representation of each character on the string?</p>
<blockquote>
<p><strong>Answer:</strong></p>
<p>Polynomial Hash:</p>
<p>Here is an example of a polynomial hash. Not necessary for your answer, but everyone seemed to not find good resources:<br>
<span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>h</mi><mo>(</mo><mi>s</mi><mo>)</mo><mo>=</mo><msub><mi>s</mi><mrow><mo>[</mo><mn>0</mn><mo>]</mo></mrow></msub><mo>∗</mo><mn>3</mn><msup><mn>1</mn><mrow><mo>(</mo><mi>n</mi><mo>−</mo><mn>1</mn><mo>)</mo></mrow></msup><mo>+</mo><msub><mi>s</mi><mrow><mo>[</mo><mn>1</mn><mo>]</mo></mrow></msub><mo>∗</mo><mn>3</mn><msup><mn>1</mn><mrow><mo>(</mo><mi>n</mi><mo>−</mo><mn>2</mn><mo>)</mo></mrow></msup><mo>+</mo><mi mathvariant="normal">.</mi><mi mathvariant="normal">.</mi><mi mathvariant="normal">.</mi><mo>+</mo><msub><mi>s</mi><mrow><mo>[</mo><mi>n</mi><mo>−</mo><mn>1</mn><mo>]</mo></mrow></msub><mo>∗</mo><mn>3</mn><msup><mn>1</mn><mrow><mo>(</mo><mn>0</mn><mo>)</mo></mrow></msup></mrow><annotation encoding="application/x-tex">h(s) = s_{[0]}*31^{(n-1)}+s_{[1]}*31^{(n-2)}+ ... + s_{[n-1]}*31^{(0)}</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.938em;"></span><span class="strut bottom" style="height: 1.2932em; vertical-align: -0.3552em;"></span><span class="base"><span class="mord mathit">h</span><span class="mopen">(</span><span class="mord mathit">s</span><span class="mclose">)</span><span class="mrel">=</span><span class="mord"><span class="mord mathit">s</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.3448em;"><span class="" style="top: -2.5198em; margin-left: 0em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mopen mtight">[</span><span class="mord mathrm mtight">0</span><span class="mclose mtight">]</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.3552em;"></span></span></span></span></span><span class="mbin">∗</span><span class="mord mathrm">3</span><span class="mord"><span class="mord mathrm">1</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.938em;"><span class="" style="top: -3.113em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mopen mtight">(</span><span class="mord mathit mtight">n</span><span class="mbin mtight">−</span><span class="mord mathrm mtight">1</span><span class="mclose mtight">)</span></span></span></span></span></span></span></span></span><span class="mbin">+</span><span class="mord"><span class="mord mathit">s</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.3448em;"><span class="" style="top: -2.5198em; margin-left: 0em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mopen mtight">[</span><span class="mord mathrm mtight">1</span><span class="mclose mtight">]</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.3552em;"></span></span></span></span></span><span class="mbin">∗</span><span class="mord mathrm">3</span><span class="mord"><span class="mord mathrm">1</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.938em;"><span class="" style="top: -3.113em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mopen mtight">(</span><span class="mord mathit mtight">n</span><span class="mbin mtight">−</span><span class="mord mathrm mtight">2</span><span class="mclose mtight">)</span></span></span></span></span></span></span></span></span><span class="mbin">+</span><span class="mord mathrm">.</span><span class="mord mathrm">.</span><span class="mord mathrm">.</span><span class="mbin">+</span><span class="mord"><span class="mord mathit">s</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.3448em;"><span class="" style="top: -2.5198em; margin-left: 0em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mopen mtight">[</span><span class="mord mathit mtight">n</span><span class="mbin mtight">−</span><span class="mord mathrm mtight">1</span><span class="mclose mtight">]</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.3552em;"></span></span></span></span></span><span class="mbin">∗</span><span class="mord mathrm">3</span><span class="mord"><span class="mord mathrm">1</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.938em;"><span class="" style="top: -3.113em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mopen mtight">(</span><span class="mord mathrm mtight">0</span><span class="mclose mtight">)</span></span></span></span></span></span></span></span></span></span></span></span></span></span></p>
</blockquote>
<pre class=" language-cpp"><code class="prism  language-cpp"><span class="token comment">//constants = 31,33,37,39 and 41</span>
<span class="token keyword">double</span>  <span class="token function">polynomial_hash</span><span class="token punctuation">(</span>string s<span class="token punctuation">,</span> <span class="token keyword">double</span> C<span class="token punctuation">)</span>
<span class="token punctuation">{</span>
	<span class="token keyword">double</span> h <span class="token operator">=</span>  <span class="token number">0</span><span class="token punctuation">;</span>
	<span class="token keyword">for</span> <span class="token punctuation">(</span><span class="token keyword">double</span> n <span class="token operator">=</span> <span class="token punctuation">(</span>s<span class="token punctuation">.</span><span class="token function">length</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token operator">-</span>  <span class="token number">1</span><span class="token punctuation">)</span><span class="token punctuation">;</span> n <span class="token operator">&gt;=</span>  <span class="token number">0</span><span class="token punctuation">;</span> n<span class="token operator">--</span><span class="token punctuation">)</span>
	<span class="token punctuation">{</span>
		h <span class="token operator">+</span><span class="token operator">=</span> <span class="token punctuation">(</span><span class="token keyword">double</span><span class="token punctuation">)</span>s<span class="token punctuation">[</span>i<span class="token punctuation">]</span> <span class="token operator">*</span>  <span class="token function">pow</span><span class="token punctuation">(</span>C<span class="token punctuation">,</span> n<span class="token punctuation">)</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	<span class="token keyword">return</span> h<span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre>
<blockquote>
<p><strong>Real answer:</strong> is that a polynomial hash function will provide a better more dispersed hash value for words that a simple summation will not. For example: <code>stop , spot , tops , pots</code>  will all result in the same hash value using a summed hash function.  Where a polynomial hash would disperse them much better.</p>
<p><a href="https://repl.it/@rugbyprof/polynomialhash">https://repl.it/@rugbyprof/polynomialhash</a></p>
</blockquote>
<hr>
<h3 id="question-8">Question 8</h3>
<p><strong>Problem:</strong> Given the table of hash functions below, label the function with the correct function name.<br>
<strong>Function Names:</strong> <code>Shift-Add-XOR hash</code> ,<code>Modified Bernstein</code>, <code>Additive</code>, <code>Rotating</code> ,<code>XOR</code>, <code>FNV hash</code></p>

<table>
<thead>
<tr>
<th align="center">1</th>
<th align="center">2</th>
<th align="center">3</th>
<th align="center">4</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center"><code>h += p[i];</code></td>
<td align="center"><code>h = (h &lt;&lt; 4) ^ (h &gt;&gt; 28) ^ p[i];</code></td>
<td align="center"><code>h ^= p[i];</code></td>
<td align="center"><code>h ^= (h &lt;&lt; 5) + (h &gt;&gt; 2) + p[i];</code></td>
</tr>
</tbody>
</table><blockquote>
<p><strong>Answer</strong>:</p>
<ol>
<li>Additive</li>
<li>Rotating</li>
<li>XOR</li>
<li>Shift-Add-XOR hash</li>
</ol>
</blockquote>
<hr>
<h3 id="question-9">Question 9</h3>
<p><strong>Given:</strong> Suppose you have table size 9 and when you have collisions you increment 3 every time.<br>
<strong>Problem:</strong> Describe why this is a problem, and how it effects the search space in your table.<br>
<strong>Proposed Solution:</strong> What could you do the alleviate the problems that occur because of the initial choices made? Describe the relationship between table size and the increment size.</p>
<blockquote>
<p><strong>Answer:</strong></p>
<p>With the given table size and increment, you would only use about <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mfrac><mrow><mn>1</mn></mrow><mrow><mn>3</mn></mrow></mfrac></mrow><annotation encoding="application/x-tex">\frac{1}{3}</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.845108em;"></span><span class="strut bottom" style="height: 1.19011em; vertical-align: -0.345em;"></span><span class="base"><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.845108em;"><span class="" style="top: -2.655em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathrm mtight">3</span></span></span></span><span class="" style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line hide-tail" style="height: 0.04em;"><svg width="400em" height="400em" viewBox="0 0 400000 400000" preserveAspectRatio="xMinYMin slice"><path d="M0 0 h400000 v400000 h-400000z M0 0 h400000 v400000 h-400000z"></path></svg></span></span><span class="" style="top: -3.394em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathrm mtight">1</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.345em;"></span></span></span></span><span class="mclose nulldelimiter"></span></span></span></span></span></span> of the table leaving <span class="katex--inline"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mfrac><mrow><mn>2</mn></mrow><mrow><mn>3</mn></mrow></mfrac></mrow><annotation encoding="application/x-tex">\frac{2}{3}</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="strut" style="height: 0.845108em;"></span><span class="strut bottom" style="height: 1.19011em; vertical-align: -0.345em;"></span><span class="base"><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.845108em;"><span class="" style="top: -2.655em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathrm mtight">3</span></span></span></span><span class="" style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line hide-tail" style="height: 0.04em;"><svg width="400em" height="400em" viewBox="0 0 400000 400000" preserveAspectRatio="xMinYMin slice"><path d="M0 0 h400000 v400000 h-400000z M0 0 h400000 v400000 h-400000z"></path></svg></span></span><span class="" style="top: -3.394em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathrm mtight">2</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.345em;"></span></span></span></span><span class="mclose nulldelimiter"></span></span></span></span></span></span> unused, thereby causing more than necessary collisions and degrading the overall performance of the table.</p>
<p>One solution is to increase the <code>probe increment</code> every time to ensure you don’t jump the same increment, thereby increasing your chances of using all slots. Also, make sure your <code>probe increment</code> is <code>relatively prime</code> to the size of the table. This also helps ensure the hash function doesn’t fixate on a subset of table slots.</p>
</blockquote>
<hr>
</div>
</body>

</html>
