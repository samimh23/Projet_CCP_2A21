#ifndef NOTES_H
#define NOTES_H


class Notes
{
    public:
        void Notes(float,float,float,float,float,float);
        void Notes (float,float,float,float,float);
        float calcultMoyenne();
        Notes();


        Notes n1 ()
        virtual ~Notes();

    protected:

    private:
        float calculNCC();
        float test 1;
        float test 2;
        float DS;
        float Examen;
        float oral;
        float TP;
        bool avecTP;
};

#endif // NOTES_H
