#include "filework.h"

FileWork::FileWork()
{

}
bool FileWork::fromfile(QFile &file, Prodlist &a){
    file.open(QIODeviceBase::ReadWrite);
    QString txt = ".txt";
    QString filename = file.fileName();
    qDebug()<<filename;
    if(!filename.contains(txt)){
        QMessageBox bruh;
        bruh.setWindowTitle("ti loh");
                bruh.setInformativeText(
                "error 228"            );
                bruh.setText("this wrong i can feel it.");
                bruh.exec();
        return 0;
    }
    if(filename == ""){
        QMessageBox bruh;
        bruh.setWindowTitle("ti loh");
                bruh.setInformativeText(
                "error 228"            );
                bruh.setText("this wrong i can feel it.");
                bruh.exec();
        return 0;
    }
    QString s;
    QString stemp;
    Production temp;
    int entercnt;
    int entercnt2;
    while(!file.atEnd()){
        entercnt2=0;
        s = file.readLine();
        s.remove(s.length()-2,1);
        qDebug()<<"string : "<<s;
        for(int i =0;i<s.length();i++){
            if(s[i]==' '){
                entercnt2++;
            }
        }
        if(entercnt2>3){
            continue;
        }
        if(entercnt2==2){
            entercnt = 0;
            for(int i = 0 ;i <s.length();i++){
                if(s[i]==' '||s[i]=='\n'){
                    entercnt++;
                    //name_1_amount_2_dep_3
                    if(entercnt==1){
//                        if(stemp==""||stemp==" "){
//                            QMessageBox bruh;
//                            bruh.setWindowTitle("ti loh");
//                                    bruh.setInformativeText(
//                                    "error 228"            );
//                                    bruh.setText("this wrong i can feel it.");
//                                    bruh.exec();
//                            return 0;

//                        }
                        qDebug()<<"c1 - "<<stemp;
                        temp.name = stemp;
                        stemp="";
                        continue;

                    }
                    if(entercnt==2){
//                        if(stemp==""||stemp==" "){
//                            QMessageBox bruh;
//                            bruh.setWindowTitle("ti loh");
//                                    bruh.setInformativeText(
//                                    "error 228"            );
//                                    bruh.setText("this wrong i can feel it.");
//                                    bruh.exec();
//                            return 0;

//                        }
                         qDebug()<<"c2 - "<<stemp;
                         temp.amount = stemp;
                         stemp = "";
                         continue;


                    }
                    if(entercnt==3){
//                        if(stemp==""||stemp==" "){
//                            QMessageBox bruh;
//                            bruh.setWindowTitle("ti loh");
//                                    bruh.setInformativeText(
//                                    "error 228"            );
//                                    bruh.setText("this wrong i can feel it.");
//                                    bruh.exec();
//                            return 0;

//                        }
                         qDebug()<<"c3 - "<<stemp;
                         temp.department = stemp;
                         if(temp.name==""||temp.amount==""||temp.department==""){
                             break;
                         }
                         a.push_back(temp);
                         stemp="";
                         break;



                    }


                }
                stemp+=s[i];


            }

        }

    }
    file.close();
    qDebug()<<a.showsize();
//    if(!a.showsize()){
//        QMessageBox bruh;
//        bruh.setWindowTitle("ti loh");
//                bruh.setInformativeText(
//                "error 228"            );
//                bruh.setText("this wrong i can feel it.");
//                bruh.exec();
//        return 0;
//    }
    return 1;
}
void FileWork::tofile(QFile &file,Prodlist list){
    file.open(QIODeviceBase::ReadWrite|QIODeviceBase::Truncate);
    QString temp;
    for(int i =0;i<list.showsize();i++){

          temp = list.prod[i].name+" "+list.prod[i].amount+" "+list.prod[i].department+" "+'\n';

        qDebug()<<temp;
        QTextStream bruh(&file);
        bruh<<temp;
    }
    file.close();
}
