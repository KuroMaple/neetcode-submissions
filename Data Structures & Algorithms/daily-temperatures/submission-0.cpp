class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> monoDecreaseTemperatureStack;
        vector<int> result(temperatures.size());
        for(int i = 0; i < temperatures.size(); ++i) 
        {
            while(!monoDecreaseTemperatureStack.empty() && monoDecreaseTemperatureStack.top().first < temperatures[i])
            {
                pair<int, int> currentTop = monoDecreaseTemperatureStack.top();
                result[currentTop.second] = i - currentTop.second;
                monoDecreaseTemperatureStack.pop();
            }

            monoDecreaseTemperatureStack.push({temperatures[i], i});
        }

        return result;
    }
};
