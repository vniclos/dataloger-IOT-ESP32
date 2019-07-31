#ifndef _SD
#define _SD
#include "FS.h"
#include "SD_MMC.h"
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
extern bool g_SD_enable;
extern bool g_SD_Reader_enable;
extern char g_SD_type[16];
extern char g_SD_size[16];

bool fnc_dev_SD_Setup()
{
  Serial.begin(115200);
  Serial.println("=====================================");
  Serial.print(FILENAME);
  Serial.print(" compiled: ");
  Serial.print(__DATE__);
  Serial.print(" ");
  Serial.println(__TIME__);
  Serial.println("=====================================");
  pinMode(PIN_LEDINT, OUTPUT);

  g_SD_Reader_enable = false;
  g_SD_enable = false;
  strcpy(g_SD_size, "?");
  strcpy(g_SD_type, "?");
  if (!SD_MMC.begin())
  {
    Serial.println("Card Mount Failed");
    return false;
  }
  else
  {

    uint8_t cardType = SD_MMC.cardType();
    if (cardType == CARD_NONE)
    {

      strcpy(g_SD_type, "No SD mount");
      Serial.println("No SD_MMC card attached");
      return false;
    }
    g_SD_Reader_enable = true;

    Serial.print("SD_MMC Card Type: ");
    if (cardType == CARD_MMC)
    {
      strcpy(g_SD_type, "CARD_MMC");
    }
    else if (cardType == CARD_SD)
    {
      strcpy(g_SD_type, "SDSC");
    }
    else if (cardType == CARD_SDHC)
    {
      strcpy(g_SD_type, "SDHC");
    }
    else
    {
      strcpy(g_SD_type, "SD UNKNOWN");
    }
    /*
    uint64_t x=281474976710655
    unsigned char value[sizeof(x)];
    std::memcpy(value,&x,sizeof(x));
    *
     */
    Serial.println(g_SD_type);
    uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024); //MB
    //unsigned char cValue[sizeof(cardSize)];
    memcpy(g_SD_size, &cardSize, sizeof(cardSize));
    //memcpy(cValue,&cardSize,sizeof(cardSize));

    //strcpy(g_SD_size , cValue);
    Serial.printf("SD_MMC Card Size: %lluMB\n", cardSize);

    return true;
  }
}

///----------------------------------
String fncSD_listChartList(fs::FS &fs, const char *dirname, uint8_t levels)
{
  String szReply = "";
  String szFileName = "";
  String szEndWith = "csv";
  Serial.printf("Listing directory: %s\n", dirname);

  File root = fs.open(dirname);
  if (!root)
  {
    Serial.println("Failed to open directory");
    return "<tr><td colspan=\"2\">SD  Failed to open directory</td>";
    ;
  }
  if (!root.isDirectory())
  {
    Serial.println("Not a directory");
    return "<tr><td colspan=\"2\">Not sd directory</td>";
    ;
  }

  File file = root.openNextFile();

  while (file)
  {
    if (file.isDirectory())
    {

      if (levels)
      {
        fncSD_listChartList(fs, file.name(), levels - 1);
      }
    }
    else
    {
      szFileName = file.name();
      if (szFileName.endsWith("dd.csv") || szFileName.endsWith("dd.csv") || szFileName.endsWith("yy.csv"))
      {
        Serial.print("  FILE: ");
        Serial.print(file.name());
        Serial.print("=");
        Serial.print(szFileName);
        Serial.print("  SIZE: ");
        Serial.println(file.size() / 1024);
        szReply += "\n<li><a href=\"#\" onclick=\"fncChartAjaxGetFile('" + szFileName + "')\">" + szFileName + "</a></li>";
      }
    }
    file = root.openNextFile();
  }
  return szReply;
}
///----------------------------------
String fncSD_listULLIDir(fs::FS &fs, const char *dirname, uint8_t levels)
{
  String szReply = "";
  String szFileName = "";
  String szEndWith = "csv";
  Serial.printf("Listing directory: %s\n", dirname);

  File root = fs.open(dirname);
  if (!root)
  {
    Serial.println("Failed to open directory");
    return "<li>SD  Failed to open directory</li>";
    ;
  }
  if (!root.isDirectory())
  {
    Serial.println("Not a directory");
    return "<li>Not sd directory</li>";
  }

  File file = root.openNextFile();

  while (file)
  {
    if (file.isDirectory())
    {

      if (levels)
      {
        fncSD_listULLIDir(fs, file.name(), levels - 1);
      }
    }
    else
    {
      szFileName = file.name();
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("=");
      Serial.print(szFileName);
      Serial.print("  SIZE: ");
      Serial.println(file.size() / 1024);
      if (szFileName.endsWith("csv") || szFileName.endsWith("txt"))
      {

        szReply += "<tr><td><span class=\"filename\">" + szFileName + "</span></td><td> ";
        szReply += "<a class=\"btn mini\" href=\"/filedown?file=" + szFileName + "\" download=\"" + szFileName + "\">Download</a>";
        szReply += "<a class=\"btn mini\" href = \"#\" onclick=\"fncDelete('" + szFileName + "');\">Delete</a></td>\n";
      }
    }
    file = root.openNextFile();
  }
  return szReply;
}

void fncSD_createDir(fs::FS &fs, const char *path)
{
  Serial.printf("Creating Dir: %s\n", path);
  if (fs.mkdir(path))
  {
    Serial.println("Dir created");
  }
  else
  {
    Serial.println("mkdir failed");
  }
}

void fncSD_removeDir(fs::FS &fs, const char *path)
{
  Serial.printf("Removing Dir: %s\n", path);
  if (fs.rmdir(path))
  {
    Serial.println("Dir removed");
  }
  else
  {
    Serial.println("rmdir failed");
  }
}

String fncSD_readFile(fs::FS &fs, const char *path)
{
  String szReply = "";
  Serial.printf("Reading file: %s\n", path);

  File file = fs.open(path);
  if (!file)
  {
    szReply = "Failed to open file for reading";
    Serial.println(szReply);
    return szReply;
  }

  Serial.print("Read from file: ");
  while (file.available())
  {
    Serial.write(file.read());
  }

  return szReply;
}

void fncSD_writeFile(fs::FS &fs, const char *path, const char *message)
{
  Serial.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if (!file)
  {
    Serial.println("Failed to open file for writing");
    return;
  }
  if (file.print(message))
  {
    Serial.println("File written");
  }
  else
  {
    Serial.println("Write failed");
  }
}

void fncSD_appendFile(fs::FS &fs, const char *path, const char *message)
{
  Serial.printf("Appending to file: %s\n ", path);
  Serial.println(message);
  File file = fs.open(path, FILE_APPEND);
  if (!file)
  {
    Serial.println("Failed to open file for appending");
    return;
  }
  if (file.print(message))
  {
    Serial.println("Message appended");
  }
  else
  {
    Serial.println("Append failed");
  }
}

void fncSD_renameFile(fs::FS &fs, const char *path1, const char *path2)
{
  Serial.printf("Renaming file %s to %s\n", path1, path2);
  if (fs.rename(path1, path2))
  {
    Serial.println("File renamed");
  }
  else
  {
    Serial.println("Rename failed");
  }
}

void fncSD_deleteFile(fs::FS &fs, const char *path)
{
  Serial.printf("Deleting file: %s\n", path);
  if (fs.remove(path))
  {
    Serial.println("File deleted");
  }
  else
  {
    Serial.println("Delete failed");
  }
}
bool fncSD_FileExist(fs::FS &fs, const char *path)
{
  File file = fs.open(path);
  // static uint8_t buf[512];
  //size_t len = 0;
  //uint32_t start = millis();
  //uint32_t end = start;
  if (file)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void fncSD_testFileIO(fs::FS &fs, const char *path)
{
  File file = fs.open(path);
  static uint8_t buf[512];
  size_t len = 0;
  uint32_t start = millis();
  uint32_t end = start;
  if (file)
  {
    len = file.size();
    size_t flen = len;
    start = millis();
    while (len)
    {
      size_t toRead = len;
      if (toRead > 512)
      {
        toRead = 512;
      }
      file.read(buf, toRead);
      len -= toRead;
    }
    end = millis() - start;
    Serial.printf("%u bytes read for %u ms\n", flen, end);
    file.close();
  }
  else
  {
    Serial.println("Failed to open file for reading");
  }
  file = fs.open(path, FILE_WRITE);
  if (!file)
  {
    Serial.println("Failed to open file for writing");
    return;
  }

  size_t i;
  start = millis();
  for (i = 0; i < 2048; i++)
  {
    file.write(buf, 512);
  }
  end = millis() - start;
  Serial.printf("%u bytes written for %u ms\n", 2048 * 512, end);
  file.close();
}

#endif
