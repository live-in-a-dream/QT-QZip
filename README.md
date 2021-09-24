# QT-QZip


MyJlCompress::Instance()->extractDir(zipFileFullName,zipFilePath);
 
connect(MyJlCompress::Instance(),SIGNAL(Start()),this,SLOT(Start()));
connect(MyJlCompress::Instance(),SIGNAL(Progressbar(int,int,QString)),this,SLOT(Progressbar(int,int,QString)));
connect(MyJlCompress::Instance(),SIGNAL(Success()),this,SLOT(Success()));
connect(MyJlCompress::Instance(),SIGNAL(Error(int)),this,SLOT(Error(int)));
