# OptimizationProblem
Dynamic Programming Assignment I had. It may look a little weird, but the instructions were interesting, so there are multiple programs that are the same, with more stuff added. I don't know if the solution I made is correct, but I am proud of the conclusion I made. Included is a PDF with the recursive equation I implented in the code.


Here was the problem:

An editor for a publishing company is reviewing a certain number of pages per day to send
to final editing. The editor receives a certain number of pages, different, each day, during
an interval of n days. For instance, in day i the editor receives pi pages to edit. The company
receives a certain fixed revenue for each page that the editor reviews. However, due to the
limited time during the day and the degree of tiredness of the editor, not all pages that are
received may end up being reviewed. Any pages that remain at the end of the day will be
sent to other companies, and thus the profit from those pages is lost. Furthermore, the
number of pages that the editor can review in one day, reduces with every day that goes by
since the last time the editor took a day off to get rest. For instance, on the first day after
coming back from a day off the editor can review m1 pages, on the second day after the day
off the editor can review m2 pages and so on, until the last day when the editor can review
mn pages, with m1 > m2 > ...> mn. To get the editor back to high productivity, the company
can offer him/her a day off, understanding that the editor does not review any pages during
that day.
The problem. Given number of pages to be reviewd p1, p2, p3, ..., pn for a duration of n
days, and given the known efficiency decline of the editor m1, m2 , ..., mn, (considering that
on day 1 the editor just had a break the previous day), the goal is to find a schedule for the
days in which the company should offer a day off to the editor in order to maximize the
total amount of pages reviewed for the company. Develop a dynamic programming
algorithm that finds the value and solution for an optimal plan using the steps outlined
below
