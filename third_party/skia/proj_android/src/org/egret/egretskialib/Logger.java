package org.egret.egretskialib;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

public class Logger {

    private static final HashMap<String, String> ERROR_MAP_CN;
    static {
        ERROR_MAP_CN = new HashMap<String, String>();
        ERROR_MAP_CN.put("0000", "未知错误");
        ERROR_MAP_CN.put("2001", "图片格式不支");
        ERROR_MAP_CN.put("2100", "net:空参");
        ERROR_MAP_CN.put("2101", "net:服务器返回错误状态码");
        ERROR_MAP_CN.put("2102", "net:非法URL");
        ERROR_MAP_CN.put("2103", "net:IO错误");
        ERROR_MAP_CN.put("2104", "net:IO关闭操作错误");
        ERROR_MAP_CN.put("2200", "unzip:空参");
        ERROR_MAP_CN.put("2201", "unzip:IO错误");
        ERROR_MAP_CN.put("2202", "unzip:创建文件夹错");
    };

    private static final HashMap<String, String> ERROR_MAP_EN;
    static {
        ERROR_MAP_EN = new HashMap<String, String>();
        ERROR_MAP_EN.put("0000", "Unknown error");
        ERROR_MAP_EN
                .put("2001", "The following picture format is unsupported");
    }

    public enum Language {
        CN, EN
    }

    private HashMap<String, String> ERROR_MAP;
    private File log;
    private Language language;
    private FileWriter writer;

    public Logger() {
        setLanguage(Language.CN);
    }

    public String getErrorMessage(String error) {
        if (!ERROR_MAP.containsKey(error)) {
            return ERROR_MAP.get("0000");
        }
        return ERROR_MAP.get(error);
    }

    public void open(File log) {
        this.log = log;
        if (log == null) {
            writer = null;
        } else {
            try {
                writer = new FileWriter(log);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void close() {
        if (writer == null) {
            return;
        }
        try {
            writer.close();
            writer = null;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void setLanguage(Language language) {
        this.language = language;
        switch (language) {
        case CN:
            ERROR_MAP = ERROR_MAP_CN;
            break;
        case EN:
            ERROR_MAP = ERROR_MAP_EN;
            break;
        }
    }

    public Language getLanguage() {
        return language;
    }

    public synchronized void print(String message, int level) {
        // TODO: need buffer
        if (log == null || writer == null) {
            return;
        }
        try {
            String date = "";
            writer.append(date + ": " + level + ": " + message);
            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public synchronized String readLog() {
        if (log == null) {
            return null;
        }
    //    close();
  //      String result = FileUtil.readFile(log);
   //     open(log);
        return "readLog unimplement";
    }

    public synchronized void clearLog() {
        if (log == null) {
            return;
        }
        close();
        log.delete();
        open(log);
    }
}
