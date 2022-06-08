import unittest
import random
import subprocess

class RangeMaxTreeTest(unittest.TestCase):

    def test_RangeMax(self):
        def generate_tree_value(power):
            limit = 2 << power
            result = dict()
            file = open("./Unittest/input.txt", "w")
            for i in range(limit):
                key = random.randint(1, limit)
                while key in result:
                    key = random.randint(1, limit)
                value = random.randint(1, limit)
                result[key] = value
                file.write(f"{key}:{value}\n")
            file.close()
            return result

        tree_values = generate_tree_value(5)

        self.assertEqual(True, False)  # add assertion here


if __name__ == '__main__':
    unittest.main()
