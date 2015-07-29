package org.egret.egretskialib;

import java.io.File;
import java.util.HashMap;
import java.util.Map.Entry;


import android.util.Log;

public class EgretContext {
    private enum LogLevel {
        All, Debug, Info, Warn, Error, Off
    }

    private static final String EGRET_RUNTIME_TAG = "EgretContext";
    
    public static final String APP_CONTEXT = "app_context";
    public static final String LOG = "log";

    public static final String NET_CONTEXT = "net_context";
    private static EgretContext instance = null;
    
    public static Boolean isRunning = false;
    
    private HashMap<String, Object> objects;
    private Logger log;
    private File logFile;
    private LogLevel loglevel;

    public static void newInstance() {
        instance = new EgretContext();
    }

    private EgretContext() {
        objects = new HashMap<String, Object>();
        log = new Logger();
        loglevel = LogLevel.All;
    }

    public static void releaseInstance() {
        if (instance == null) {
            return;
        }
        if (instance.objects != null) {
            for (Entry<String, Object> entry : instance.objects.entrySet()) {
                entry.setValue(null);
            }
        }
        instance.log.clearLog();
        instance.log.close();
        instance.log = null;
        instance = null;
    }

    public static void setObject(String name, Object object) {
        instance.objects.put(name, object);
    }

    public synchronized static Object getObject(String name) {
        if (instance == null || instance.objects == null || name == null
                || !instance.objects.containsKey(name)) {
        	Log.e(EGRET_RUNTIME_TAG, "not found " + name);
            return null;
        }
        return instance.objects.get(name);
    }

    public static void setLogFile(File log) {
        if (instance != null) {
            instance.logFile = log;
            instance.log.open(log);
        }
    }

    public static File getLogFile() {
        if (instance != null) {
            return instance.logFile;
        }
        return null;
    }

    public static void clearLog() {
        if (instance != null) {
            instance.log.clearLog();
        }
    }

    public static String loadLog() {
        if (instance != null) {
            return instance.log.readLog();
        }
        return null;
    }

    public static String getErrorMessage(String error, String source) {
        if (instance == null) {
            return "error " + error + "::" + source;
        } else {
            return "error " + error + ":"
                    + instance.log.getErrorMessage(error) + ":" + source;
        }
    }

    public static void setLogLevel(int level) {
        if (0 < level && level < LogLevel.values().length) {
            instance.loglevel = LogLevel.values()[level];
        } else {
            instance.loglevel = LogLevel.All;
        }
    }

    private interface ILogger {
        public void log(String tag, String content);
    }

    private static void logMessage(String filename, String message,
            LogLevel level, ILogger logger) {
        String msg = filename + ":" + message;
        if (instance == null) {
            logger.log(EGRET_RUNTIME_TAG, msg);
        } else if (instance.loglevel.compareTo(level) <= 0) {
            logger.log(EGRET_RUNTIME_TAG, msg);
            instance.log.print(msg, level.ordinal());
        }
    }

    public static void logDebug(String filename, String message) {
        logMessage(filename, message, LogLevel.Debug, new ILogger() {
            @Override
            public void log(String tag, String content) {
                Log.d(tag, content);
            }
        });
    }

    public static void logInfo(String filename, String message) {
        logMessage(filename, message, LogLevel.Info, new ILogger() {
            @Override
            public void log(String tag, String content) {
                Log.i(tag, content);
            }
        });
    }

    public static void logWarn(String filename, String message) {
        logMessage(filename, message, LogLevel.Warn, new ILogger() {
            @Override
            public void log(String tag, String content) {
                Log.w(tag, content);
            }
        });
    }

    public static void logError(String filename, String message) {
        ILogger logger = new ILogger() {
            @Override
            public void log(String tag, String content) {
                Log.e(tag, content);
            }
        };
        logMessage(filename, message, LogLevel.Error, logger);
    }

    

}
