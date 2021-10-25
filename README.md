# LiquidDemocracy

Assumptions 1: Multiple votes by the same person render all its votes invalid.
Assumptions 2: Empty line terminates intput.

I pick more complex test scenarios as it's like integration testing. Simple input/output are for UT.

Test data 1 - Empty input:
Input:

Output:
0 Invalid

Test data 2 - Simple incorrect input:
Input:
Bill likes Banana
Bob picks Orange
Lis vote for Water
Ann delegate Ann
Rob delegates Rob
Ted delegate Pit
Pit delegate Ted

Output:
9 Invalid

Test 3 - Multiple votes scenarios:
Ed pick Egg
Ed pick Bread
Ann delegate Bob
Ann delegate Rob
Ted delegate Tim
Ted pick Egg

Output:
6 Invalid

Test 4 - All Correct Input
Input:
Ted pick Pizza
Ed delegate Ted
Rob delegate Liz
Liz delegate Tim
Tim pick Salad
George pick Pizza
Od pick Orange
Dog pick Bone
Cat pick Milk
Cow pick Milk

Output:
3 Salad
3 Pizza
2 Milk
1 Orange
1 Bone
0 Invalid

Test 5 - Mixed Input
Ted pick Pizza
Ed delegate Ted
Rob delegate Liz
Tom delegate Ann
Ter dont now
Liz delegate Tim
Tim pick Salad
Ann delegate Tom
George pick Pizza
Od pick Orange
Dog pick Bone
Monkey delegate Monkey
Cat pick Milk
Just Anything!
Cow pick Milk

Output:
3 Salad
3 Pizza
2 Milk
1 Orange
1 Bone
5 Invalid
