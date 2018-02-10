//Import statements
import java.io.BufferedWriter;
import java.io.FileWriter;

public class BasicFileWriter
{
    public static void main(String args[])
    {
        // The name of the file we are writing to. We can also put a path in
        // here to write to a specific location.
        String FILENAME = "myfile.txt";

        // When used, the FileWriter object will immediately put it's output
        // to the file. So FileWriter output attempts to write to the file as
        // fast as possible. Maybe this is a good thing in some
        // circumstances, but I think it would be better to write data in
        // chunks. We employ a BufferedWriter object to capture the
        // FileWriter output into a collection of bytes that can be written
        // to the file.
        FileWriter fWriter = null;
        BufferedWriter bWriter = null;

        // Wrapping our attempt to write to the file inside a try / catch
        // statement allows us to trap some errors if they happen
        try
        {
            // Here is the content that we will write to the file.
            String fileContent = "Dude, I'm totally writing to a file!!";

            // These lines instantiate FileWriter and BufferedWriter objects.
            // When instantiating the FileWriter object we pass in the file
            // name that we are writing to. If no path is given in our
            // filename, the file will be created and written in the root
            // directory.
            fWriter = new FileWriter(FILENAME);

            // The BufferedWriter object is instantiated on this line and the
            // FileWriter object is passed in as an argument.
            bWriter = new BufferedWriter(fWriter);

            // Now that we have our buffer and writer objects created, we can
            // attempt to write content to the file. Here is what
            // (I think) this is doing. The BufferedWriter object will receive
            // the content to be written, and then pass that content as a
            // whole to the FileWriter so it can be written to the file as a
            // chunk. If we did not do it this way, the content would be read
            // passed into the FileWriter object, converted to bytes on the
            // fly, and immediately written, byte by byte as it is converted,
            // to the file. By buffering we are increasing the performance of
            // this action.
            bWriter.write(fileContent);
        }

        // The catch statement will trap and display any exception that is
        // created when we are attempting to create our writer objects, open
        // or create the file, or write content.
        catch(Exception e)
        {
            System.out.println("Unable to write to file : " + e.getMessage());
        }

        // This 'finally' statement will always happen, regardless of what
        // happens in our try/catch statement. If we put this code into the
        // try statement and we received an error, it would never be
        // processed. Additionally, if we put this code at the bottom of our
        // program and ran into an error half way through, it would never be
        // processed. Placing the code into a finally statement allows us to
        // ensure that it is run every time.
        finally
        {
            // Another try and catch statement to trap any error that happens
            // when closing the files.
            try
            {
                // The last thing we want to do is close out our writer
                // objects. This is a best practice since if you leave the
                // writer open you are at best wasting system resources, and
                // at worst you could lock this file for editing while other
                // resources are trying to use it. We check to make sure it
                // is not already disposed of, and then we call the close()
                // method.
                if (bWriter != null) {
                    bWriter.close();
                }

                if (fWriter != null) {
                    fWriter.close();
                }
            }
            // Our final catch reveals any errors that popped up when we were
            // attempting to close the writer and buffer objects.
            catch (Exception e)
            {
                System.out.println("Unable to close writer objects :"
                        + e.getMessage());
            }
        }
    }
}