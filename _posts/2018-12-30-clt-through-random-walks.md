---
layout: post
title: "Central Limit Theorem through Random Walks"
date: 2018-12-30
---

The central limit theorem is a beautiful result I recently learned about in my
probability course, and I thought a beautiful application of it can be seen in
random walks! 

## The Central Limit Theorem

*Theorem:* Let $\{X_i\}_{i=1}^n $ be an i.i.d. sequence of random variables
whose expectation exists and has finite non-zero variance $\sigma^2$. Then:

$$
\begin{equation}
\lim_{n \to \infty} \mathbb{P} \left[
\frac{(X_1 + \dots + X_n) - n \mu}{\sigma \sqrt{n}} \leq x
\right] = \Phi(x), x \in \mathbb{R}
\end{equation}
$$

Where $\Phi$ is the standard normal distribution function.

This theorem is remarkable in its generality, the $X_i$'s can be continuous,
discrete or neither, and can even be missing higher order moments. However,
the limiting behavior of the sum always is normal.

## Intro to Random Walks

Suppose a _very_ drunk person stands on the real number line, at initial
position $\eta$. We want to chart his movements along this number line, and
interestingly enough at each step he appears to move in accordance to some
sequence of random variables $\{X_i\}$. So his position at step $n$ will be
denoted by $S_n = \eta + X_1 + \dots + X_n$.

For example, suppose that:
$$
\mathbb{P}[X_i = k] = \begin{cases}
\frac{1}{2}, & k = \pm 1 \\
0, & \text{else}
\end{cases}
$$
Then this person has a $1/2$ probability to step one unit to the right or left.
Such a random walk would look like:

![]({{ site.url }}/_posts/clt_through_random_walks/pm1rv.png){: .center-image }
