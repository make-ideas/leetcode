package leetcode.editor.cn;

//不使用运算符 + 和 - ，计算两整数 a 、b 之和。 
//
// 示例 1: 
//
// 输入: a = 1, b = 2
//输出: 3
// 
//
// 示例 2: 
//
// 输入: a = -2, b = 3
//输出: 1 
// Related Topics 位运算 
// 👍 375 👎 0

public class SumOfTwoIntegers{
	public static void main(String[] args) {
		Solution solution = new SumOfTwoIntegers().new Solution();
		int a = -1, b = 1;
		solution.getSum(a, b);
	}
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
	public int getSum(int a, int b) {
		if (b!=0){
			int xor=a^b;
			int and = (a&b)<<1;
			return getSum(xor,and);
		}else{
			return a;
		}
	}
}
//leetcode submit region end(Prohibit modification and deletion)

}