#ifndef UTILITY_H
#define UTILITY_H
#include"QDebug"
#include"mainpaintscene.h"
//#include"Shape.h"
//struct DrawFile{
//     MainPaintScene *mMainPaintScene;
//     QList<Shape*> mShapeList;
//};


class Utility
{
public:
    Utility();
    void saveFile(QString filePath, MainPaintScene *mMainPaintScene);
//    friend QDataStream& operator << (QDataStream& stream, const Utility& utility)
//    {
//     stream<<utility.mMainPaintScene;
//     return stream;
//    }

//    friend QDataStream& operator >>(QDataStream& stream,const Utility& utility)
//    {
//     stream >>utility.mMainPaintScene ;
//     return stream;
//    }
    void saveFileToEdit(QString filePath, MainPaintScene *mMainPaintScene);
    MainPaintScene* readFile(QString filePath);


    /**
     * @brief cssFromColor  工具方法，返回相关颜色的脚本语言
     * @param color
     * @return
     */
    QString cssFromColor(QColor color);


};

#endif // UTILITY_H
