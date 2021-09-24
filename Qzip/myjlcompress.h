#ifndef MYJLCOMPRESS_H
#define MYJLCOMPRESS_H

#include <QObject>
#include "quazip.h"
#include "quazipfile.h"
#include "quazipfileinfo.h"
#include <QString>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include "QMutex"
class  MyJlCompress
        : public QObject
{
    Q_OBJECT
public:
    //����
    static MyJlCompress* Instance()
    {
        static QMutex mutex;
        if (!m_instance) {
            QMutexLocker locker(&mutex);
            if (!m_instance)
                m_instance = new MyJlCompress;
        }

        return m_instance;
    }
private:
    QStringList extractDir(QuaZip &zip, const QString &dir);
    QStringList getFileList(QuaZip *zip);
    QString extractFile(QuaZip &zip, QString fileName, QString fileDest);
    QStringList extractFiles(QuaZip &zip, const QStringList &files, const QString &dir);
    /// Compress a single file.
    /**
      \param zip Opened zip to compress the file to.
      \param fileName The full path to the source file.
      \param fileDest The full name of the file inside the archive.
      \return true if success, false otherwise.
      */
    bool compressFile(QuaZip* zip, QString fileName, QString fileDest);
    /// Compress a subdirectory.
    /**
      \param parentZip Opened zip containing the parent directory.
      \param dir The full path to the directory to pack.
      \param parentDir The full path to the directory corresponding to
      the root of the ZIP.
      \param recursive Whether to pack sub-directories as well or only
      files.
      \return true if success, false otherwise.
      */
    bool compressSubDir(QuaZip* parentZip, QString dir, QString parentDir, bool recursive,
                               QDir::Filters filters);
    /// Extract a single file.
    /**
      \param zip The opened zip archive to extract from.
      \param fileName The full name of the file to extract.
      \param fileDest The full path to the destination file.
      \return true if success, false otherwise.
      */
    bool extractFile(QuaZip* zip, QString fileName, QString fileDest);
    /// Remove some files.
    /**
      \param listFile The list of files to remove.
      \return true if success, false otherwise.
      */
    bool removeFile(QStringList listFile);

public:
    /// Compress a single file.
    /**
      \param fileCompressed The name of the archive.
      \param file The file to compress.
      \return true if success, false otherwise.
      */
    bool compressFile(QString fileCompressed, QString file);
    /// Compress a list of files.
    /**
      \param fileCompressed The name of the archive.
      \param files The file list to compress.
      \return true if success, false otherwise.
      */
    bool compressFiles(QString fileCompressed, QStringList files);
    /// Compress a whole directory.
    /**
      Does not compress hidden files. See compressDir(QString, QString, bool, QDir::Filters).

      \param fileCompressed The name of the archive.
      \param dir The directory to compress.
      \param recursive Whether to pack the subdirectories as well, or
      just regular files.
      \return true if success, false otherwise.
      */
    bool compressDir(QString fileCompressed, QString dir = QString(), bool recursive = true);
    /**
     * @brief Compress a whole directory.
     *
     * Unless filters are specified explicitly, packs
     * only regular non-hidden files (and subdirs, if @c recursive is true).
     * If filters are specified, they are OR-combined with
     * <tt>%QDir::AllDirs|%QDir::NoDotAndDotDot</tt> when searching for dirs
     * and with <tt>QDir::Files</tt> when searching for files.
     *
     * @param fileCompressed path to the resulting archive
     * @param dir path to the directory being compressed
     * @param recursive if true, then the subdirectories are packed as well
     * @param filters what to pack, filters are applied both when searching
     * for subdirs (if packing recursively) and when looking for files to pack
     * @return true on success, false otherwise
     */
    bool compressDir(QString fileCompressed, QString dir,
                            bool recursive, QDir::Filters filters);

public:
    /// Extract a single file.
    /**
      \param fileCompressed The name of the archive.
      \param fileName The file to extract.
      \param fileDest The destination file, assumed to be identical to
      \a file if left empty.
      \return The list of the full paths of the files extracted, empty on failure.
      */
    QString extractFile(QString fileCompressed, QString fileName, QString fileDest = QString());
    /// Extract a list of files.
    /**
      \param fileCompressed The name of the archive.
      \param files The file list to extract.
      \param dir The directory to put the files to, the current
      directory if left empty.
      \return The list of the full paths of the files extracted, empty on failure.
      */
    QStringList extractFiles(QString fileCompressed, QStringList files, QString dir = QString());
    /// Extract a whole archive.
    /**
      \param fileCompressed The name of the archive.
      \param dir The directory to extract to, the current directory if
      left empty.
      \return The list of the full paths of the files extracted, empty on failure.
      */
    QStringList extractDir(QString fileCompressed, QString dir = QString());
    /// Get the file list.
    /**
      \return The list of the files in the archive, or, more precisely, the
      list of the entries, including both files and directories if they
      are present separately.
      */
    QStringList getFileList(QString fileCompressed);
    /// Extract a single file.
    /**
      \param ioDevice pointer to device with compressed data.
      \param fileName The file to extract.
      \param fileDest The destination file, assumed to be identical to
      \a file if left empty.
      \return The list of the full paths of the files extracted, empty on failure.
      */
    QString extractFile(QIODevice *ioDevice, QString fileName, QString fileDest = QString());
    /// Extract a list of files.
    /**
      \param ioDevice pointer to device with compressed data.
      \param files The file list to extract.
      \param dir The directory to put the files to, the current
      directory if left empty.
      \return The list of the full paths of the files extracted, empty on failure.
      */
    QStringList extractFiles(QIODevice *ioDevice, QStringList files, QString dir = QString());
    /// Extract a whole archive.
    /**
      \param ioDevice pointer to device with compressed data.
      \param dir The directory to extract to, the current directory if
      left empty.
      \return The list of the full paths of the files extracted, empty on failure.
      */
    QStringList extractDir(QIODevice *ioDevice, QString dir = QString());
    /// Get the file list.
    /**
      \return The list of the files in the archive, or, more precisely, the
      list of the entries, including both files and directories if they
      are present separately.
      */
    QStringList getFileList(QIODevice *ioDevice);

private:
    static MyJlCompress* m_instance;
public:
    explicit MyJlCompress(QObject *parent = nullptr){};
signals:
    //��ʼ��ѹ
    void Start();
    //��ѹ����
    void Progressbar(int i,int all,QString name);
    //��ѹ�ɹ�
    void Success();
    //��ѹʧ��
    void Error(int code);
};

#endif // MYJLCOMPRESS_H
