class Solution {
public:
    string intToRoman(int num) {
        string s;
        while(num>0)
        {
            if(num>=1000)
            {
               s.push_back('M');
               num=num-1000;
            }
            else if(num>=900)
            {
                s.push_back('C');
                s.push_back('M');
                num=num-900;
            }
            else if(num>=500)
            {
                s.push_back('D');
                num=num-500;
            }
            else if(num>=400)
            {
              s.push_back('C');  
              s.push_back('D');
              num=num-400;
            }
            else if(num>=100)
            {
                s.push_back('C');
                num=num-100;
            }
            else if(num>=90)
            {
                s.push_back('X');
                s.push_back('C');
                num=num-90;
            }
            else if(num>=50)
            {
                s.push_back('L');
                num=num-50;
            }
            else if(num>=40)
            {
                s.push_back('X');
                s.push_back('L');
                num=num-40;
            }
            else if(num>=10)
            {
                s.push_back('X');
                num=num-10;
            }
            else if(num==9)
            {
                s.push_back('I');
                s.push_back('X');
                num=num-9;
            }
            else if(num>=5)
            {
                s.push_back('V');
                num=num-5;
            }
            else if(num==4)
            {
                s.push_back('I');
                s.push_back('V');
                num=num-4;
            }
            else if(num>0)
            {
                s.push_back('I');
                num=num-1;
            }
            cout<<s<<endl;
            
        }
        return s;
    }
};