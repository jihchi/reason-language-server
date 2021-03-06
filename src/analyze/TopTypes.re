
/* Aliases to make the intents clearer */
type uri = string;
type filePath = string;
type moduleName = string;

/* Here are the things that will be different between jbuilder things */
type package = {
  basePath: filePath,

  /* Might change based on bsconfig.json / .merlin */
  includeDirectories: list(filePath),
  compilationFlags: string,

  /* Depend on bsb having already run */
  localModules: list((moduleName, (filePath, filePath))),
  dependencyModules: list((moduleName, (string, option(string)))),
  pathsForModule: Hashtbl.t(moduleName, (filePath, option(filePath))),

  opens: list(string),

  tmpPath: string,

  buildSystem: BuildSystem.t,
  compilerPath: filePath,
  refmtPath: filePath,
};

type settings = {
  formatWidth: option(int),
  perValueCodelens: bool,
  opensCodelens: bool,
  dependenciesCodelens: bool,
  clientNeedsPlainText: bool,
  crossFileAsYouType: bool,
};

type state = {
  rootPath: filePath,
  rootUri: uri,
  settings,

  documentText: Hashtbl.t(uri, (string, int, bool)),
  documentTimers: Hashtbl.t(uri, float),

  /* package, */
  packagesByRoot: Hashtbl.t(string, package),
  rootForUri: Hashtbl.t(uri, string),

  cmtCache: Hashtbl.t(filePath, (float, SharedTypes.file)),
  cmiCache: Hashtbl.t(filePath, (float, SharedTypes.file)),
  compiledDocuments: Hashtbl.t(uri, AsYouType.result),
  lastDefinitions: Hashtbl.t(uri, SharedTypes.full),

  /* workspace folders... */
};
