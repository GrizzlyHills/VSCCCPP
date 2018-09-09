    #include <iostream>
    using namespace::std;

    int excel_number = 0;
    void excel_count(float score)
    {
        if(score > 85)
            excel_number++;   
        return;
    }
    int main()
    {
        float score = 0;
        for(int i = 0;i < 5;i++){
            cin >> score;
            excel_count(score);
        }
        cout << excel_number << endl;
        system("pause");
        return 0;
    }