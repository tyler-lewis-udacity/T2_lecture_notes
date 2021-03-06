'''
Kalman Filter 1D Constant Temperature

'''

true_temp    = 72.0

measurements = [75.0,
                73.0,
                70.0,
                71.0,
                74.0,
                73.0,
                72.0,
                72.0,
                69.0,
                70.0]
E_measurement = 4.0 #...due to cheap thermometer, never changes

n    = len(measurements)
mean = sum(measurements)/float(n)
std  = ((sum([(x - mean)**2 for x in measurements]))/n)**0.5

# Set the initial values for the temperature estimate (estimate) and E_estimate (error in estimate)
initial_estimate   = 68.0 # ...we guess that the initial temperatue estimate is 68 degrees
prev_estimate = initial_estimate
initial_E_estimate = 2.0 #...actually, we believe the initial temperature estimate is 68 +or- 2 degrees
prev_E_estimate = initial_E_estimate
t = -1

print("true_temp          = {}".format(true_temp))
print("n                  = {}".format(n))
print("mean               = {}".format(round(mean, 3)))
print("std                = {}".format(round(std, 3)))
print("")
print("initial_estimate   = {}".format(initial_estimate))
print("initial_E_estimate = {}".format(initial_E_estimate))
print("E_measurement      = {}".format(E_measurement))
print("------------------------------------------")

# # 1.) Update the old values and update the time
# prev_estimate   = estimate
# prev_E_estimate = E_estimate
# t = t + 1
# measurement = measurements[t]
# print("------------------------------------------")
# print("t               = {}".format(t))
# print("measurement     = {}".format(measurement))
# print("prev_estimate   = {}".format(prev_estimate))
# print("prev_E_estimate = {}".format(prev_E_estimate))

# # 2.) Calculate the Kalman Gain
# KG = prev_E_estimate/ (prev_E_estimate + E_measurement)
# print("KG              = {}".format(KG))

# # 3.) Get the new temperature estimate
# estimate = prev_estimate + KG*(measurement - prev_estimate)
# print("estimate        = {}".format(estimate))

# # 4.) Get the new estimate error
# E_estimate = (1 - KG)*prev_E_estimate
# print("E_estimate      = {}".format(E_estimate))

def update_KG(prev_E_estimate, E_measurement):
    KG = prev_E_estimate/(prev_E_estimate + E_measurement)
    return KG

def update_estimate(prev_estimate, KG, measurement):
    estimate = prev_estimate + KG*(measurement - prev_estimate)
    return estimate

def update_error(prev_E_estimate, KG):
    E_estimate = (1 - KG) * prev_E_estimate
    return E_estimate

def kalman_filter(prev_estimate, prev_E_estimate, measurement, E_measurement):
    KG = update_KG(prev_E_estimate, E_measurement)
    estimate = update_estimate(prev_estimate, KG, measurement)
    E_estimate = update_error(prev_E_estimate, KG)
    return estimate, E_estimate, KG

def print_list(l):
    for item in l:
        print(item)
    print("------------------------------")
'''------------------------------------------------------------------------'''

# t = 0
# measurement = measurements[t]
# print("t               = {}".format(t))
# print("prev_estimate   = {}".format(prev_estimate))
# print("prev_E_estimate = {}".format(prev_E_estimate))
# print("measurement     = {}".format(measurement))
# print("E_measurement   = {}".format(E_measurement))

# estimate, E_estimate, KG = kalman_filter(prev_estimate, prev_E_estimate, measurements[t], E_measurement)
# print("KG         = {}".format(KG))
# print("estimate   = {}".format(estimate))
# print("E_estimate = {}".format(E_estimate))
# print("-----------------------------------------")
KG_list = list()
estimate_list = list()
E_estimate_list = list()

for t, measurement in enumerate(measurements):
    print("t               = {}".format(t))
    print("prev_estimate   = {}".format(prev_estimate))
    print("prev_E_estimate = {}".format(prev_E_estimate))
    print("measurement     = {}".format(measurement))
    print("E_measurement   = {}".format(E_measurement))

    estimate, E_estimate, KG = kalman_filter(prev_estimate, prev_E_estimate, measurements[t], E_measurement)
    print("KG         = {}".format(KG))
    print("estimate   = {}".format(estimate))
    print("E_estimate = {}".format(E_estimate))

    # Store values
    KG_list.append(KG)
    estimate_list.append(estimate)
    E_estimate_list.append(E_estimate)

    # Reset variables
    prev_estimate = estimate
    prev_E_estimate = E_estimate
    print("-----------------------------------------")


print_list(KG_list)
print_list(estimate_list)
print_list(E_estimate_list)
