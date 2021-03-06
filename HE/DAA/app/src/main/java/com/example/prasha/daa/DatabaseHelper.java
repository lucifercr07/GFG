package com.example.prasha.daa;

/**
 * Created by prasha on 3/1/17.
 */

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHelper extends SQLiteOpenHelper {

    public static final String DATABASE_NAME="Data.db";
    public static final String Table_NAME="Data";
    public static final String COL_0="Algo";
    public static final String COL_1="best";
    public static final String COL_2="avg";
    public static final String COL_3="worst";
    public static final String COL_4="spworst";

    private static final String DB_PATH_SUFFIX = "/databases/";
    static Context ctx;
    public DatabaseHelper(Context context) {
        super(context, DATABASE_NAME, null, 1);
        ctx = context;
    }

    public Cursor getDatas(String name) {
        SQLiteDatabase db = this.getWritableDatabase();
        String s="SELECT * FROM " + Table_NAME + " WHERE " + COL_0 + " = '"+ name +"'";
        Cursor res= db.rawQuery(s,null);
        return res;
    }

    public void CopyDataBaseFromAsset() throws IOException{

        InputStream myInput = ctx.getAssets().open(DATABASE_NAME);

// Path to the just created empty db
        String outFileName = getDatabasePath();

// if the path doesn't exist first, create it
        File f = new File(ctx.getApplicationInfo().dataDir + DB_PATH_SUFFIX);
        if (!f.exists())
            f.mkdir();

// Open the empty db as the output stream
        OutputStream myOutput = new FileOutputStream(outFileName);

// transfer bytes from the inputfile to the outputfile
        byte[] buffer = new byte[1024];
        int length;
        while ((length = myInput.read(buffer)) > 0) {
            myOutput.write(buffer, 0, length);
        }

// Close the streams
        myOutput.flush();
        myOutput.close();
        myInput.close();

    }
    private static String getDatabasePath() {
        return ctx.getApplicationInfo().dataDir + DB_PATH_SUFFIX
                + DATABASE_NAME;
    }

    public SQLiteDatabase openDataBase() throws SQLException{
        File dbFile = ctx.getDatabasePath(DATABASE_NAME);

        if (!dbFile.exists()) {
            try {
                CopyDataBaseFromAsset();
                System.out.println("Copying sucess from Assets folder");
            } catch (IOException e) {
                throw new RuntimeException("Error creating source database", e);
            }
        }

        return SQLiteDatabase.openDatabase(dbFile.getPath(), null, SQLiteDatabase.NO_LOCALIZED_COLLATORS | SQLiteDatabase.CREATE_IF_NECESSARY);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {

    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
// TODO Auto-generated method stub

    }
}
