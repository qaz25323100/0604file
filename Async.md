
## Task.WaitAll  
  
    public static void Main()
        {
            var files = new ConcurrentBag<string>();

            string[] directories = new string[] { "D:\\", "C:\\", "D:\\PMS" };

            List<Task> tasks = new List<Task>();

            foreach (string directory in directories)
            {
                Task t = Task.Run(() =>
                {
                    foreach (string file in Directory.GetDirectories(directory))
                    {
                        files.Add(file);
                    }
                });
                tasks.Add(t);
            }

            Task.WaitAll(tasks.ToArray());

            foreach (Task t in tasks)
                Console.WriteLine("Task {0} Status: {1}", t.Id, t.Status);

            foreach(string s in files)Console.WriteLine(s);
        }
