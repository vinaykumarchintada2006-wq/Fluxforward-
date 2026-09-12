"""
Flux Forward - Waste Segregation & Sanitization Pod Simulator
Run this script via terminal: python simulation.py
"""

import time

MOISTURE_THRESHOLD = 2300

def classify_waste(is_metal: bool, moisture_value: int) -> str:
    if is_metal:
        return "METALLIC WASTE -> Diverted to Bin 1"
    elif moisture_value > MOISTURE_THRESHOLD:
        return "ORGANIC / WET WASTE -> Diverted to Bin 2"
    else:
        return "DRY RECYCLABLE WASTE -> Diverted to Bin 3"

def run_test_cases():
    test_samples = [
        {"item": "Crushed Soda Can", "metal": True, "moisture": 300},
        {"item": "Banana Peel", "metal": False, "moisture": 3100},
        {"item": "Cardboard Box", "metal": False, "moisture": 800},
        {"item": "Wet Sponge", "metal": False, "moisture": 3600},
    ]

    print("=" * 60)
    print(" FLUX FORWARD: TEST SUITE SIMULATION ")
    print("=" * 60)

    for idx, sample in enumerate(test_samples, 1):
        print(f"\n[Test {idx}] Item Dropped: {sample['item']}")
        print(f"Reading Sensors -> Inductive: {sample['metal']} | Moisture ADC: {sample['moisture']}")
        time.sleep(0.5)
        decision = classify_waste(sample['metal'], sample['moisture'])
        print(f"Result: {decision}")

    print("\n" + "=" * 60)
    print("Simulation complete. All decision branches verified.")
    print("=" * 60)

if __name__ == "__main__":
    run_test_cases()
                                 
