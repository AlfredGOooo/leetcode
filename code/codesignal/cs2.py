def trafficRide(lights, cycles, destinations) -> int:
    time = 0
    curr_loc = 0
    for des in destinations:
        if curr_loc < des:
            for i in range(len(lights)):
                light_loc = lights[i]
                if curr_loc < light_loc <= des:
                    cycle = cycles[i]
                    diff = light_loc - curr_loc
                    time += diff
                    curr_loc = light_loc - 1
                    next_available_time = ((time + cycle) // (cycle * 2)) * (cycle * 2) + cycle
                    time = next_available_time
                    curr_loc = light_loc
            diff = des - curr_loc
            time += diff
            curr_loc = des
        else:
            for i in range(len(lights) - 1, -1, -1):
                light_loc = lights[i]
                if des <= light_loc <= curr_loc:
                    cycle = cycles[i]
                    diff = curr_loc - (light_loc + 1)
                    time += diff
                    curr_loc = light_loc + 1
                    next_available_time = ((time + cycle) // (cycle * 2)) * (cycle * 2) + cycle
                    time = next_available_time
                    curr_loc = light_loc
            diff = curr_loc - des
            time += diff
            curr_loc = des
    return time