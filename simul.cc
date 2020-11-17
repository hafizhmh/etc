// ndn-simple-withl2tracer.cpp

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/ndnSIM-module.h"

namespace ns3 {

int
main(int argc, char* argv[])
{
  CommandLine cmd;
  cmd.Parse(argc, argv);

  AnnotatedTopologyReader topologyReader("", 1);
  topologyReader.SetFileName("scratch/topo-tugas.txt");
  topologyReader.Read();
  /****************************************************************************/
  // Install NDN stack on all nodes
  ndn::StackHelper ndnHelper;
  ndnHelper.setPolicy("nfd::cs::lru");
  ndnHelper.setCsSize(1000);
  ndnHelper.InstallAll();
  /****************************************************************************/
  // Installing global routing interface on all nodes
  ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
  ndnGlobalRoutingHelper.InstallAll();
  /****************************************************************************/
  // Getting containers for the consumer/producer
  Ptr<Node> consumer1 = Names::Find<Node>("Jakarta");
  Ptr<Node> consumer2 = Names::Find<Node>("Osaka");
  Ptr<Node> consumer3 = Names::Find<Node>("LA");
  Ptr<Node> consumer4 = Names::Find<Node>("Melbourne");
  
  Ptr<Node> producer1 = Names::Find<Node>("China"); 
  /****************************************************************************/
  ndn::AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  consumerHelper.SetAttribute("Frequency", StringValue("1000")); // interests per Second
  consumerHelper.SetAttribute("Randomize", StringValue("uniform"));
  /****************************************************************************/
  // install a Consumer application
  consumerHelper.SetPrefix("/dst");
  consumerHelper.Install(consumer1);

  consumerHelper.SetPrefix("/dst");
  consumerHelper.Install(consumer2);

  consumerHelper.SetPrefix("/dst");
  consumerHelper.Install(consumer3);

  consumerHelper.SetPrefix("/dst");
  consumerHelper.Install(consumer4);
  /****************************************************************************/
  ndn::AppHelper producerHelper("ns3::ndn::Producer");
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
  /****************************************************************************/
  // Register /dst prefix with global routing controller and
  // install producer that will satisfy Interests in /dst1
  ndnGlobalRoutingHelper.AddOrigins("/dst", producer1);
  producerHelper.SetPrefix("/dst");
  producerHelper.Install(producer1);
  
  /*****************************************************************************/
  // Calculate and install FIBs
  ndn::GlobalRoutingHelper::CalculateRoutes();

  Simulator::Stop(Seconds(10.0));

  /****************************************************************************/
  // Tracer:

  ndn::L3RateTracer::InstallAll("rate-trace.txt", Seconds(1.0));
  L2RateTracer::InstallAll("drop-trace.txt", Seconds(1.0));
  ndn::AppDelayTracer::InstallAll("app-delays-trace.txt");

  Simulator::Run();
  Simulator::Destroy();

  return 0;
}

} // namespace ns3

int
main(int argc, char* argv[])
{
  return ns3::main(argc, argv);
}