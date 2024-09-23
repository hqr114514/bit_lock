import java.util.*;
import java.io.*;
public class bit_lock {
    public static void main(String args[]) {
        Scanner cin=new Scanner(System.in);
        String op=cin.nextLine();
        String fileIn=cin.nextLine();
        String fileOut=cin.nextLine();
        File Fin=new File(fileIn);
        File Fout=new File(fileOut);
        int GB=1024*1024*1024;
        try{
            InputStream fin=new FileInputStream(Fin);
            OutputStream fout=new FileOutputStream(Fout);
            if(op.indexOf("E")!=-1||op.indexOf("e")!=-1) {
                Random Rad=new Random(114514);
                byte salt[]=new byte[1];
                salt[0]=(byte)(Rad.nextInt(255));
                fout.write(salt);
                while(fin.available()>=GB) {
                    byte tmp[]=new byte[GB];
                    fin.read(tmp);
                    for(int i=0;i<GB;i++) {
                        tmp[i]=(byte)(((int)tmp[i])^((int)salt[0]));
                    }
                    fout.write(tmp);
                }
                int len=fin.available();
                byte tmp[]=new byte[len];
                fin.read(tmp);
                for(int i=0;i<len;i++) {
                    tmp[i]=(byte)(((int)tmp[i])^((int)salt[0]));
                }
                fout.write(tmp);
            }
            else {
                byte salt[]=new byte[1];
                fin.read(salt);
                while(fin.available()>=GB) {
                    byte tmp[]=new byte[GB];
                    fin.read(tmp);
                    for(int i=0;i<GB;i++) {
                        tmp[i]=(byte)(((int)tmp[i])^((int)salt[0]));
                    }
                    fout.write(tmp);
                }
                int len=fin.available();
                byte tmp[]=new byte[len];
                fin.read(tmp);
                for(int i=0;i<len;i++) {
                    tmp[i]=(byte)(((int)tmp[i])^((int)salt[0]));
                }
                fout.write(tmp);
            }
        }
        catch (IOException e) {
            System.out.println("ERROR!");
        }
        return ;
    }
}
