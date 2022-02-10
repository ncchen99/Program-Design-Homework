Lec06
=====

Collatz conjecture (3n + 1 Problem)
-----------------------------------

### Description

<div>

**Collatz conjecture**, also known as **3n+1 problem**, which is a
conjecture in mathematics that is about a sequence defined as follows:
Let `S1` be a positive integer which is the start of the sequence, and

-   if `Sn` is **even**, then `Sn+1 = Sn / 2`

-   if `Sn` is **odd**, then `Sn+1 = 3 * Sn + 1`

The conjecture is that for any given positive integer `S1` (\<= 10\^5),
the sequence will reach 1.

e.g. Given `S1 = 22`, the sequence will be:
`22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1`

As students of NCKU, we are interested in this conjecture, please write
a program to help us do some research in this conjecture.

</div>

### Input

A positive integer S1, (1 \<= S1 \<= 10\^5)

### Output

Two integer L, M within a line, where L represents the length of the
sequence and M is the maximum number of the sequence.

### Loader Code

<div>

Your code will be judge using this program:

</div>

<div>

### Sample1

#### Input

    22

#### Output

    16 52

</div>

<div>

### Sample2

#### Input

    999

#### Output

    50 11392

</div>

Congruent OOXX Triangle
-----------------------

### Description

<div>

Given a number `h`, print a **congruent triangle** with height `h` that
consists of OOXX (the last line must be only consist of O).

For example, `h=5`:

![](data:image/png;base64,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)

</div>

### Input

An integer h. (1 \<= h \<= 150)

### Output

A congruent triangle consisted of OX, and the bottom of the triangle
must only contains O.

### Loader Code

<div>

Your code will be judge using this program:

</div>

<div>

### Sample1

#### Input

    1

#### Output

    O

</div>

<div>

### Sample2

#### Input

    5

#### Output

        O
       OXO
      OXOXO
     OXOXOXO
    OOOOOOOOO

</div>

Pokémon Go II - Pokémon Gym
---------------------------

### Description

<div>

Ariel likes to play Pokémon Go! She had many battles in pokémon gym. She
needs a tool to record the battle\'s result.\
She had `n` battles. Each battle is three-on-three and each pokémon has
**combat power(CP)**. If the combat power of Ariel\'s pokémon is more
than competitor\'s, then Ariel\'s pokémon wins. If Ariel has more wins
than competitor, she wins the battle. Please record each battle is
\"**Win**\", \"**Tie**\", or \"**Lose**\" and calculate the **win
rates**.\
\
For example,

Ariel had a battle. Her three pokémons\' combat power are 200, 300 and
400, and the competitor\'s three pokémons\' combat power are 100,350 and
400. Then,

**200\>100** Win

**300\<350** Lose

**400=400** Tie

Because Ariel and competitor had the same number of wins, this battle is
\"**Tie**\". Ariel had one battle and the number of wins is 0, then the
win rates is **0/1 = 0.00%**

------------------------------------------------------------------------

Ariel 最喜歡玩 Pokémon Go!
她參加了很多場道館賽，所以她需要有個小幫手幫忙記錄!\
她參加了 `n` 場道館對戰，每一場中，對方派出 3 隻寶可夢，Ariel 也同樣派出
3 隻寶可夢應戰，每隻寶可夢都有 **CP 值**，CP 值較高的寶可夢獲勝，CP
值相同的寶可夢對戰則為平手，獲勝的寶可夢數量最多的那一方獲勝，若雙方獲勝的寶可夢數量相同時，則這一場為平手，請幫忙紀錄每一場比賽
Ariel 是 **獲勝**、**平手**或是**輸**，並算出**勝場率**。

舉例:

Ariel 參加了一場道館賽，派出了三隻寶可夢，其CP值分別為
200、300、400，而對方派出的寶可夢其 CP 值為 100、350、400\
所以\
\
**200\>100** Win

**300\<350** Lose

**400=400** Tie\
\
雙方各有一隻寶可夢獲勝，所以這場比賽比賽為平手(**Tie**)，而Ariel總共參加了一場比賽，勝場數為
0 ，所以**勝場率**為 **0/1 = 0.00%**

</div>

### Input

First line, an integer n represents the number of battles. Then, there
are 3\*n lines after the first line. (1\<=n\<=50) Each line has two
integer a, b represent combat power(CP) of Ariel\'s and competitor\'s
pokémon, respectively.(0\<=a,b\<=1000)

### Output

You have output n battle\'s results and the win rates. If Ariel wins the
battle, output \"Win\". If Ariel loses the battle, output \"Lose\". if
the battle is tie, output \"Tie\". The win rates is a floating-point
number with two digits after the decimal point.

### Loader Code

<div>

Your code will be judge using this program:

</div>

<div>

### Sample1

#### Input

    3
    1000 200
    500 100
    400 399
    100 200
    222 122
    200 200
    133 500
    122 444
    700 900

#### Output

    Win
    Tie
    Lose
    33.33%

</div>

<div>

### Sample2

#### Input

    1
    200 500
    100 222
    500 900

#### Output

    Lose
    0.00%

</div>

The happiest girl in the world
------------------------------

### Description

<div>

On the way back to the Skyland in an airship, crews face a huge attack
from monsters. Willem falls out of the airship after several waves of
attack, Chtholly notices that and wants to save him, please help her
calculate how many meters remained before Willem reaches the ground. You
may use the following equation to calculate the distance Willem has
traveled through: ![Screenshot from 2021-10-13
13-54-46.png](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAMkAAAA1CAYAAADrls9nAAAABHNCSVQICAgIfAhkiAAAABl0RVh0U29mdHdhcmUAZ25vbWUtc2NyZWVuc2hvdO8Dvz4AAAA9aVRYdENyZWF0aW9uIFRpbWUAAAAAADIwMjHlubTljYHmnIgxM+aXpSAo6YCx5LiJKSAxM+aZgjU05YiGNTTnp5Kmwf+tAAAQw0lEQVR4nO2ce1yO5xvAv8/bgU6GlPOxDG0p3kLIWM5jDsMyp2nYzGFs7McWW5uMOUdymNnpR8wYI8yhX84qvGKoNEQpkb1Jx7fn/v1Rq7SOqsX7eb6fz/v59D7Pcz/3dR+u+76u677eJCGEQEFBoUhUVS2AgsKzjqIkCgoloCiJgkIJKEqioFACipIoKJSAoiQKCiWgf0qS/pCHqVUthII+oR9KImeQFB9F8J41zHAfwKLjclVLpKBHGFa1AOUnjcMLx+N/34aWRlGcvp1Od5TzUYWKQw+UpDo9PbfiJgSc8GJ3YGRVC6SgZ+iBkmQjSRJIUlWLoaCH6IdPoqBQiShKoqBQAnqpJEpis0JFopdKIstKCFih4tAbx/1JKnknybrDoY1buJDwFzciY7DoPo25Hk7UqtxaFZ6SpIvb+OZAFNr46/yZYstb/5lFv+bGpS6vpztJ5SpJ/C+L+G9WX6Z4euO7qDf3/Gby1cGkSq1T4SmRz7Fm8Vnsxs7l82V+vNcgkM9mbSSiDK/QKyWRdToAMjMzK7We9KwM4kI1xAOqBp1xaZ6KRlOWblcoDxnBPiw/mlK6h3UZkBxOcEQKklSNjp2dkG5dJOxh6RdSvTC3zvmO5etjqSTfj8PAxIQLPu4M97dA6jCN7R92qfD6mozcwIGROQECXSwx8ca0b/8SQojs85rnCF3ccTYs/4mQBzrkdGjqNpGp4zphXeLymcmfe5ewYud10gwhTWeNq8d03unaAINKlTiNY79epe4009I9buzCJ3v25QZz4mNjyGrRhfY1y1Cl0BNkWS7yU160F/zF6h1hIrWQezH+E0WPcZtEeFr56/nX0QYJz77OYqTvFZEmy0J+HC7Wju4sRvqGibQSiiYc8RQe8w6LeJ0QspwlkiL3iDmDBojFwYX1UgXyKEB8OGWruPc045oWIrxf6yfmHX1QpnmhN+aWJElFfsrHXXYtX8L3gdfRFbiju7GFRUdeZqmPBy1L7wc+I2Ry2mcB+xMcGeLeGmNAMn2R0W+0J+I7P/YXa45E4L/6PA7ublipBJKkwsJ2INPesOTXnSeozNjiw8MH0b3amzplLpnEyWXr0E5ax7zutco0L/RGSSqNRyEEXwNbR0fM8p+/JAWzZtMjJiyfTjuLW5w4cbvqZHwqbqPRJILKkjq1yJ00FvXqYSqfI/B4cYEILVptAscDQknON9m0Wi2mFjWg0s6p7nPwdxV9etUu4+KXxc2fV/A/Ry8WDmxM+vkTXCilSwNl8ElSruxk9XdB3LyvRbR8k09GGeG/eg/xmUbU6TODuf0al0HoZ4jMOxxa58v+6HSS49J4efRoGt+Ko9W4odhVAzlMwyXZkkFOzfIGRncL/0W7sBw0BsPoy1xOPExg1FBcXctaeSoRu33ZGBRHhjYegy4eDDaNJKXTBPo2q+z1K4GEBMDA4EkfQqXCgCyuX78JOBRR9iWcnaqzy38q7jff5lPPd+io28+6w7WZsNKJ7F5K5eIPi/j+ZCT367nj/WlHojb6cCA2jXs37vNCj6ksmGhL+E8+/HQ+ieToCJJtx+L1xfCid+XY/Ry16MsKcwEUUJKseALXLObnGxJGGSkYtJ/AgglqTAHtmVWsvtGRcQO0XLvygMs7z1B/QRkGqzQ2mXxnl5gxfb0IfyyEnHVOfNW7g+jcc7rYGRcjds/oJZyH+YmosluIVU/qZfHN+FfFIK8gcT9LFnLSUTGnh1qonaaIdesmisGDBolermqh7tBd9Bs8WAwe9pU4ni5E+PrhwlmtFurcj7OYcyizjJVrxaml7qKH+0qheSSErLsntr/vItTqzmJ+UFalNPdJbomN7mqhVs8Sv+vy7PMH298VarVadJ73v2Ltdjn+d/HJgE7Z7XcdIAb2Hy++DU/JK3Nrs5jqdUykRK4TQ9SuYtDwKWLZyTiRLstCDl0s3JwGiqkzpwjPnVHisSyEHL9FvK12FjP2JBdZZ9RGD+EZmFaIXOlCs3yIGOh1UmhlWcgPA8XcPsPExighRPJhMbtb/rFSC/XwdSKqDD5JKXYSHWc276Tx+E20NMmO3kgiCwOXobxuFcfycB3N+6lpKEQRWbjx7Fvgxb7YYqqQJCQkshN5zegy9SvcW1X2SqrjyjderP/Tia9WuVJbAsmiM10cJA5F2+E2aTLvvnuXzWNex6/mdPx9BmMBgECatJ2zE8tnUjw+7cMXW7X0Xf8ebc0EkmRFV5dWLD6rws6ucFMi88K3zNoYStEB7uw+/Ls/VTZDWTCzBzUKfbYRPXq2YkPkHe7EAE2y2xYRkf1Tg4y0NGQoMlIlWXfjnZHtubQ1mr/u3iU2JZ5tK3fQafkY2lSHW4fPUK/3WIzu/E48MnaDZ/OBizUGkgSmppiKWG7Xnceiwc0xlQATE0yQ+UubBJgVUmMEASeb0H9ctX9OMzmEX3bdpumHL2EB6C4dQ1PNnt6WAszc+DootFypSqVQEgnbUd7YNzPMNjdiLhGWKNG2nQMq6QVm7zuCzD82v3zU5TXPtfR/1vKpHu5lzU9/YtJ7Ct3M/7bJw7l2TWDWqS3NAR6FEhoOrac4YwFP2MHlCwhE4796Nwl1R9K/vXHOu7K4di0SGoygrWXhpYzaebBqrUfZBrzIxUuFzRhPJp+aws8+21DP6kPtP7cSEF0PM7RUr1OnGIc1ieBVU1ga487anX0wCN6Et/dmzgSvYuaChmxb8Cq1e33MpPoqIvwukW7clZHDmmQrCJAUHs5dWvL+SCf+DuSKq1e4Rg16vVi38GZcCiC4VX8mGxZiaolMdDrB6WWjmXiqCy5uI9mxuyUm+fqpPONVCiUxwKp5nr+RGhZGJE2Z0PaF3IpLs+ZX9PmBk5NTmcuEhobm/v341DFCdRKd1O3yOuFuGGEJEvZt7VEBmedDuSjXY4RTw4qVP+44QREC0/5q2uRejCAsLI3qbe1pWULxCpPFuA3j/b7H5ufd/LZuLbVe7se0N+9y8Fw4Taytiy539QcW7KzL1D39aWgIUpd3WbO9Oz/Omcqqw79x6pMe9GvcAgsSORJ2B9qMwN7o78IyYRcvIWr1xaFxXluunjlLkrETTvaFtU3mXMB5HPtPL3yuGbgwepKa4LXn0BzdgeboHoLu/sj3b9uUr39yKPNh4iXNRWQLV9o2z7mQ9ZD4h2bUrfPvxkDzT/inIT4mBpnG2NlZ5A5UWlgY4TTBw74GkiRxKTiENLOOOLWuCInzERtDLNDKzi5v0O+HcTEW7EbZV/JhXH5kHqdZ0nXUVLqRfTiasNWXLMmG7t0aFamMf125QmyLzjjWyKew5q0YM388R/r/QnQsYAtkXuTiFag/3D5fyDaKixeTMXRwwC73WgRHjsZg3GkSnatnkhj3CIt6luTqlS6YgCtOjPi4sJB+BnFXwrEYsZ79Q29zNfR3Nn7tx+lDQcS+bUPDCuilUijJXfbNfZ9VqePxX2lHaMhDsHuZl3Jkvbf7c76SPVk5zKqI8nH85vUZe4vzSZ7AjG4zljKqTeX6JOYWFoABVrliZ3A+WEOWhSuOLQBuEhqSgEE7NQ4qIEPD8s8v8+bC0eXveHMLLFBhZWWZO+jJwcFcoxGjHS2LnJyZ5zcyc31xPkkBbEbw9cduvFDE7Uf7P6bvvBDclv3OF69UQ5ISOHz4EiadPRnSPO85kZpAQqYl1jWyx8S0Vk2Mb9/ghg6sjfK9UKdDZ9Ka1k1zvl/VoEmvhpNjvlUmUYMmGtoMcaDa39cijnD0jgHOHl0xTQxg3jIVny95PVdJ0k8GcLPLOFoV0oa0wC8YMfsAjvMC8RnUmLavvsOYs1vRPG5OvSJNzbJRspKknuPgoViqD7dGnNvJkThjVI0MUAHyg0BWB9RntE9RCgJQj4GfrWfAM+aTWHfuyosrthIZmQnOEL13Pl/uSUTV2YGXJYBEEh9CfVcbTOVEji1ZT9bgZTQoTcennGfjJ35csZ+M9zvt+UcChU1XujbYREhkFLKbLWkRW5m9NIgM09dwsC36tUbtJ7Jm/cQK8kmynfIssxa82NAQSCFymzc/Jb/BkmUD8zKa5TBWjHiHLdpXWBiwlN7mYOzqwVTb91nifZDlc/rSpDroHmr44YsdmE/zxTVnVt0NCyNBehlHB8Ncxc/UaPgDa0Y41s+9Ju7f5wGteMPZjMjtB7EcuhKLXLlTCQqI4ZWpNhSW3a2Ni0PXYgSjXzHPFjchkF81LZi8sEuFHQKWrCQmLgwZ5sz2eH8++9mBz7Yv5aj3OqZPD8LMyIp+nh+hNinEmSrAM5fT1PQtFs6/g9ficUyqW5taTc2pIcDS0TFnUrdj7EeDCf/vSmZEmNNs6Hw+dDYpXTtun2HviQvEhPxC6Nvt6VbQfjKw571FH5HgPZdxF+pS07oh1cxB1cQR+1KMbEX1pWmfmXx52Ztv545ivyEYN+uNl994nGrmq0NVi2a29bG6Z0PdajnjbGTLWz4bqOW3gSVT/dGmZaAzqo/LqDWsdGuEKqdswgMtDdwm0CVfntTD5BTqvDSM3nnOGJLzUCZ0WUrQ4v8Q1eEDPu5knFf/o0AOaN34T6PC8+LqDv8cz+il/DD/Q7YZZpGqewGXOUsZ2cKo4uZcaWPFBXOhsrKyKiw3qtw8Che7F08TY9wHCrce/cSwCfPE5hN3RHopi8uyLHSnvhTd1b3EknP/bE/Z2/lY3D57WKyZMln8GFt8OVmWhfw4QMzooBbuG6KqpD9Lk+tW1L2SyhZ3vTTPJu6aLqbtuF9iv1R0vl5+Sr0jFcyFUqlUFZQbVU7k2/h7LufWK/PYtGU3B3ctZahZMGtmeOB58F7hZZLC+W3zFkISs79KksylU8E8MutAh5f++XjZ22lKow52mKsa0bpgkEgkotnxLTsvJ+e+OzX4FJosazp0bF4l/VmaXLei7pVUtrjrJT/7gEOHJHr3KtpPK0sbnpbnP3crYg9bTl4h8Fg4mZKEwQt2jPx0PG3FA476buFqIeZ79I4v8PJdz4Fr2al4f533ZckvyXScPpGuFRSkSwn5kVPN+uFYsIcvfcecRWv5ITAaAPneMZb4HMKkz0zG2ldM3XpD/EECzfvRw6Jq/dnn//ckhsZUk1K4E3WXFCEwlSSwaoFNDQiLjSTisaCN+ZMri7XrG/Q7vpeEPXOY/UsK2tQ69Pz6R0Z1aZBrT5ePWH7dY8ikue0wKOhsNuvJiB4aTkf9wOxZmTzWZtJkuC/fj2hP7QqoWZ+IOXgCq/4r/hn4+JeRhHjGwk5PQeq9GFJqNqC2Uc42/mg37/f4kmCLwaw9+ikdipj4BZte0du0KOZHWJVd9/OP4PqBfeh6DqB1FS/lz/9OAphYN8Qk3/ek0ye5DDQc9DrqYspV9sQs7v2KUpSEhG3fAVUtBKAPPklB5HC+Xx9IRrO3+HyivR42UOHfRi92kjwyCf9mAdsz+7Bgwwc4miortkL50Quf5G+Szi7i7YVa3vPzplf9ZyA8raAX6I01Isf+xrzl9/DwXZCjIDpOr/UjpOAP0xUUyoh+KEnaH6z78hAuCxfxWkNVzg5yneDQRxgZ6M1GqVBFPP/mlkjg4JyxeEc0pF1Tc1QSyFk6MpNj+IPh7Ng0EivF7FIoB8+/435yLV5HEsgggZMF/mFJ9f4Nn+JfzygoPMnzv5PkUFwzFAdeoTw8/ztJDooiKFQW+uG4KyhUIoqSKCiUgKIkCgoloCiJgkIJKEqioFACipIoKJTA/wEADfdTbleAxQAAAABJRU5ErkJggg==)

![](https://i.imgur.com/203N6L5.gif)

</div>

### Input

An integer h that indicates the height of the airship, 1000 \<= h \<=
10000

### Output

The remained distance, in floating-point number, for each second until
Willem reaches the ground, each occupies a line and is rounded to the
first digit after the decimal point.

### Loader Code

<div>

Your code will be judge using this program:

</div>

<div>

### Sample1

#### Input

    1000

#### Output

    1000.0
    995.1
    980.4
    955.9
    921.6
    877.5
    823.6
    759.9
    686.4
    603.1
    510.0
    407.1
    294.4
    171.9
    39.6

</div>
