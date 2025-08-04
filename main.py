class Solution:
    def intToRoman(self, num: int) -> str:
        if not 1 <= num <= 3999:
            return "Error"

        val_symbols = [
            (1000, "M"), (900, "CM"),
            (500, "D"), (400, "CD"),
            (100, "C"), (90, "XC"),
            (50, "L"), (40, "XL"),
            (10, "X"), (9, "IX"),
            (5, "V"), (4, "IV"),
            (1, "I")
        ]
        result = ""

        while num > 0:
            for x, y in val_symbols:    #tuple values -> (x,y)
                while num >= x:
                    result += y
                    num -= x
        return result

x = Solution()
print(x.intToRoman(3999))



