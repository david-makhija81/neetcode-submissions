class Solution {
    public String simplifyPath(String path) {
        String[] directories = path.split("/");

        Stack<String> directoryHierarchy = new Stack<>();

        for (String directory: directories) {
            if (directory.equals("..")) {
                if (!directoryHierarchy.empty()) {
                    directoryHierarchy.pop();
                }
            } else if (
                (!directory.equals("")) &&
                (!directory.equals("."))
            ) {
                directoryHierarchy.push(directory);
            }
        }

        String newPath = "";

        while (!directoryHierarchy.empty()) {
            newPath = "/" + directoryHierarchy.pop() + newPath;
        }

        return (!newPath.equals("")) ? newPath : "/";
    }
}