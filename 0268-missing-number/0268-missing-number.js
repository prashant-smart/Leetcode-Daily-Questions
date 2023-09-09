/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    var newArr=[]
    //[0,n]->[0,1,2,3,4,5,6,7,8,9.....n]
    // i=0->>>>>>>>>> i
    for(var i=0;i<=nums.length;i++){
        newArr.push(i);
    }
    for(var i=0;i<newArr.length;i++){
        var check=0;
        for(var j=0;j<nums.length;j++){
            if(nums[j]===newArr[i]){
                check=1
            }
        }
        if(!check)
            return newArr[i];
    }
};