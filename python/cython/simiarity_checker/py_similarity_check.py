from difflib import SequenceMatcher
import matplotlib.pyplot as plt
import timeit

timeit.template = """
def inner(_it, _timer{init}):
    {setup}
    _t0 = _timer()
    for _i in _it:
        retval = {stmt}
    _t1 = _timer()
    return _t1 - _t0, retval
"""


ratios_times = []
q_ratios_times = []
errors = []

for i in range(10000):
    str1 = "привет" * 3*i + "лол" * i
    str2 = "привет" * 3*i + "kek" * i

    ratio_time, ratio = timeit.Timer(SequenceMatcher(None, str1, str2).ratio).timeit(number=1000)
    q_ratio_time, q_ratio = timeit.Timer(SequenceMatcher(None, str1, str2).real_quick_ratio).timeit(number=1000)

    errors.append(abs(ratio - q_ratio))
    ratios_times.append(ratio_time)
    q_ratios_times.append(q_ratio_time)




fig = plt.figure()
ax = fig.add_subplot(121)
ax.plot(ratios_times, label="slower")
ax.plot(q_ratios_times, label="faster")

ax = fig.add_subplot(122)
ax.plot(errors, label="error")

plt.legend()
plt.show()


